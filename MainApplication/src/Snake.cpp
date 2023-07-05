#include "Snake.hpp"
#include <string>
#include <stdexcept>

Snake::Snake(InitializeGame::SnakePosition initialBodyPosition, Direction initialDirection)
{
	if (initialBodyPosition.size() < MIN_LENGTH)
		throw std::invalid_argument(std::string("The length of the snake must be at least ")  + std::to_string(MIN_LENGTH) + "\n");
	if (initialBodyPosition.size() > MAX_LENGTH)
		throw std::invalid_argument("The length of the snake must be at most " + std::to_string(MAX_LENGTH) + "\n");
	m_bodyPosition = initialBodyPosition;
	m_currentDirection = m_lastMovementDirection = initialDirection;
	m_snakeJustExtended = false;
	m_snakeMovedAfterDirectionChange = true;
}
void Snake::move()
{
	if (m_snakeJustExtended)
		m_snakeJustExtended = false;
	else
	{
		for (size_t i = 1; i < length(); ++i)
			m_bodyPosition[i - 1] = m_bodyPosition[i]; 
	}

	switch (m_currentDirection)
	{
		case UP:
			--getHead().y;
			m_lastMovementDirection = UP;
			break;
		case DOWN:
			++getHead().y;
			m_lastMovementDirection = DOWN;
			break;
		case LEFT:
			--getHead().x;
			m_lastMovementDirection = LEFT;
			break;
		case RIGHT:
			++getHead().x;
			m_lastMovementDirection = RIGHT;
			break;
	}
	m_snakeMovedAfterDirectionChange = true;
}

bool Snake::extend()
{
	if (length() == MAX_LENGTH)
		return false;
	m_bodyPosition.push_back(getHeadPosition());
	m_snakeJustExtended = true;
	return true;
}
bool Snake::changeDirection(Direction newDirection)
{
	if (!m_snakeMovedAfterDirectionChange)
		return false;
	if (isEven(m_currentDirection) == isEven(newDirection)) // both directions are horizontal or vertical
		return false;
	m_currentDirection = newDirection;
	m_snakeMovedAfterDirectionChange = false;
	return true;
}

void Snake::setHeadPosition(const Position& newHeadPosition)
{
	getHead() = newHeadPosition;
}