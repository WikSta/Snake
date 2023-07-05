#ifndef POSITION_HPP
#define POSITION_HPP

class Position
{
public:
	short int x;
	short int y;
	explicit Position() { x = y = 0; }
	explicit Position(int x, int y) { this->x = x; this->y = y; }
	bool operator==(const Position& position) const { return x == position.x && y == position.y; }
};

#endif