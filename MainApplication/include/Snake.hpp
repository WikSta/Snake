#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Position.hpp"
#include "InitializeGame.hpp"
#include <cstddef>

class Snake
{
public:
	enum Direction { UP, RIGHT, DOWN, LEFT };

	explicit Snake(InitializeGame::SnakePosition initialBodyPosition, Direction initialDirection);
	void move();
	bool extend();
	bool changeDirection(Direction newDirection);
	void setHeadPosition(const Position& newHeadPosition);
	size_t length() const { return m_bodyPosition.size(); }
	const Position& getHeadPosition() const { return getHead(); }
	const Position& getTailPosition() const { return m_bodyPosition.front(); }
	Direction getCurrentDirection() const { return m_currentDirection; }
	Direction getLastMovementDirection() const { return m_lastMovementDirection; }
private:
	enum Limits { MIN_LENGTH = 3, MAX_LENGTH = 500 };
	InitializeGame::SnakePosition m_bodyPosition;
	bool m_snakeJustExtended;
	bool m_snakeMovedAfterDirectionChange;
	Direction m_lastMovementDirection;
	Direction m_currentDirection;
protected:
	bool isEven(unsigned short number) const { return !(number % 2); }
	Position& getHead() { return m_bodyPosition.back(); }
	const Position& getHead() const { return m_bodyPosition.back(); }
};

#endif
