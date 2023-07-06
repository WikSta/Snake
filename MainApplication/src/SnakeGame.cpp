#include "SnakeGame.hpp"
#include "Position.hpp"
#include "Board.hpp"
#include <vector>
#include <cctype>
#include <iostream>

SnakeGame::SnakeGame(Snake& snake, Board& board) : 
	MAX_SCORE((board.getWidth() - 2) * (board.getHeight() - 2) - snake.length()), m_snake(snake), m_board(board)
{
	m_snakeExtended = 0;
	m_gameIsPaused = false;
	m_score = 0;
	m_board.createFruit();
}

SnakeGame::GameResult SnakeGame::tick()
{
	if (!m_gameIsPaused)
	{
		Position previousTailPosition = m_snake.getTailPosition();
		Position previousHeadPosition = m_snake.getHeadPosition();
		Snake::Direction lastDirection = m_snake.getLastMovementDirection();
		m_snake.move();
		updateTail(previousTailPosition);
		if (headHitObstacle())
			return LOSE;
		updateHead(previousHeadPosition, lastDirection);
		m_board.setCell(m_snake.getHeadPosition(), newHeadStatus()); // new head position
		m_board.setCell(previousHeadPosition, newBodyStatus(lastDirection)); // previous head position
		if (headEatsFruit())
		{
			m_board.createFruit();
			m_snakeExtended = m_snake.extend();
			if (++m_score == MAX_SCORE)
				return WIN;
		}
	}
	return CONTINUE;
}

void SnakeGame::takeInput(Controls pressedKey)
{
	if (!m_gameIsPaused)
	{
		switch (pressedKey)
		{
		case MOVE_UP:
			m_snake.changeDirection(Snake::UP);
			break;
		case MOVE_DOWN:
			m_snake.changeDirection(Snake::DOWN);
			break;
		case MOVE_RIGHT:
			m_snake.changeDirection(Snake::RIGHT);
			break;
		case MOVE_LEFT:
			m_snake.changeDirection(Snake::LEFT);
			break;
		}
	}
}

// private methods
bool SnakeGame::headHitObstacle() const
{
	return !headEatsFruit() && m_board.getCellStatus(m_snake.getHeadPosition());
}

bool SnakeGame::headEatsFruit() const
{
	return m_board.getFruitPosition() == m_snake.getHeadPosition();
}

void SnakeGame::updateTail(Position previousTailPosition)
{
	if (!m_snakeExtended)
	{
		m_board.setCell(m_snake.getTailPosition(), newTailStatus(m_board.getCellStatus(previousTailPosition))); // new tail position
		m_board.setCell(previousTailPosition, Board::EMPTY); // previous tail position
	}
	else // if (m_snakeExtended) no need to update tail position
		m_snakeExtended = false;
}

void SnakeGame::updateHead(Position previousHeadPosition, Snake::Direction lastDirection)
{
	m_board.setCell(m_snake.getHeadPosition(), newHeadStatus()); // new head position
	m_board.setCell(previousHeadPosition, newBodyStatus(lastDirection)); // previous head position
}

Board::CellStatus SnakeGame::newHeadStatus() const
{
	Board::CellStatus newHeadCellStatus = m_board.getCellStatus(m_snake.getHeadPosition()); // current head cell status
	switch (m_snake.getCurrentDirection())
	{
		case Snake::UP:
			newHeadCellStatus = Board::HEAD_TOP;
			break;
		case Snake::DOWN:
			newHeadCellStatus = Board::HEAD_BOTTOM;
			break;
		case Snake::LEFT:
			newHeadCellStatus = Board::HEAD_LEFT;
			break;
		case Snake::RIGHT:
			newHeadCellStatus = Board::HEAD_RIGHT;
			break;
	}
	return newHeadCellStatus;
}

Board::CellStatus SnakeGame::newBodyStatus(Snake::Direction previousDirection) const
{
	Board::CellStatus newBodyCellStatus =					//	if (lastMovementDirection is vertical)
		m_snake.getLastMovementDirection() == Snake::UP ||	//		newBodyCellStatus = Board::BODY_VERTICAL
		m_snake.getLastMovementDirection() == Snake::DOWN	//	else
		? Board::BODY_VERTICAL : Board::BODY_HORIZONTAL;	//		newBodyCellStatus = Board::BODY_HORIZONTAL
	switch (m_snake.getLastMovementDirection())
	{
	case Snake::UP:
		if (previousDirection == Snake::RIGHT)
			newBodyCellStatus = Board::BODY_TOP_LEFT;
		else if (previousDirection == Snake::LEFT)
			newBodyCellStatus = Board::BODY_TOP_RIGHT;
		break;
	case Snake::DOWN:
		if (previousDirection == Snake::RIGHT)
			newBodyCellStatus = Board::BODY_BOTTOM_LEFT;
		else if (previousDirection == Snake::LEFT)
			newBodyCellStatus = Board::BODY_BOTTOM_RIGHT;
		break;
	case Snake::LEFT:
		if (previousDirection == Snake::UP)
			newBodyCellStatus = Board::BODY_BOTTOM_LEFT;
		else if (previousDirection == Snake::DOWN)
			newBodyCellStatus = Board::BODY_TOP_LEFT;
		break;
	case Snake::RIGHT:
		if (previousDirection == Snake::UP)
			newBodyCellStatus = Board::BODY_BOTTOM_RIGHT;
		else if (previousDirection == Snake::DOWN)
			newBodyCellStatus = Board::BODY_TOP_RIGHT;
		break;
	}
	return newBodyCellStatus;
}

Board::CellStatus SnakeGame::newTailStatus(Board::CellStatus previousTailStatus) const
{
	Board::CellStatus newTailStatus = previousTailStatus;
	switch (m_board.getCellStatus(m_snake.getTailPosition()))
	{
	case Board::BODY_BOTTOM_LEFT:
		if (previousTailStatus == Board::TAIL_LEFT)
			newTailStatus = Board::TAIL_TOP;
		else // previousTailStatus == Board::TAIL_BOTTOM
			newTailStatus = Board::TAIL_RIGHT;
		break;
	case Board::BODY_TOP_LEFT:
		if (previousTailStatus == Board::TAIL_LEFT)
			newTailStatus = Board::TAIL_BOTTOM;
		else // previousTailStatus == Board::TAIL_TOP
			newTailStatus = Board::TAIL_RIGHT;
		break;
	case Board::BODY_BOTTOM_RIGHT:
		if (previousTailStatus == Board::TAIL_RIGHT)
			newTailStatus = Board::TAIL_TOP;
		else // previousTailStatus == Board::TAIL_BOTTOM
			newTailStatus = Board::TAIL_LEFT;
		break;
	case Board::BODY_TOP_RIGHT:
		if (previousTailStatus == Board::TAIL_RIGHT)
			newTailStatus = Board::TAIL_BOTTOM;
		else // previousTailStatus == Board::TAIL_TOP
			newTailStatus = Board::TAIL_LEFT;
		break;
	}
	return newTailStatus;
}
