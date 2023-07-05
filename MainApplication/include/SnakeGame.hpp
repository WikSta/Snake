#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Snake.hpp"
#include "Board.hpp"

class SnakeGame
{
public:
	const unsigned short  MAX_SCORE;
	enum Controls
	{
		MOVE_UP = 'w',
		MOVE_DOWN = 's',
		MOVE_RIGHT = 'd',
		MOVE_LEFT = 'a'
	};
	enum GameResult { CONTINUE, LOSE, WIN };
	explicit SnakeGame(Snake& snake, Board& board);
	void takeInput(Controls pressedKey);
	void pause() { m_gameIsPaused = true; }
	bool isPaused() const { return m_gameIsPaused; }
	void resume() { m_gameIsPaused = false; }
	unsigned short getScore() const { return m_score; }
	GameResult tick();
private:
	Snake& m_snake;
	Board& m_board;
	unsigned short m_score;
	bool m_snakeExtended;
	bool m_gameIsPaused;
	// private methods
	bool headHitObstacle() const;
	bool headEatsFruit() const;
	Board::CellStatus newHeadStatus() const;
	Board::CellStatus newBodyStatus(Snake::Direction previousDirection) const;
	Board::CellStatus newTailStatus(Board::CellStatus previousTailStatus) const;
	void updateTail(Position previousTailPosition);
	void updateHead(Position previousHeadPosition, Snake::Direction lastDirection);
};

#endif
