#ifndef BOARD_HPP
#define BOARD_HPP

#include "Position.hpp"
#include "InitializeGame.hpp"
#include <cstddef>

class Board
{
public:
	enum CellStatus 
	{
		EMPTY, BORDER,
		BODY_BOTTOM_LEFT, BODY_BOTTOM_RIGHT, BODY_HORIZONTAL,
		BODY_TOP_LEFT, BODY_TOP_RIGHT, BODY_VERTICAL,
		HEAD_BOTTOM, HEAD_LEFT, HEAD_RIGHT, HEAD_TOP,
		TAIL_BOTTOM, TAIL_LEFT, TAIL_RIGHT, TAIL_TOP, FRUIT
	};

	explicit Board(unsigned short width, unsigned short height); // Empty Board without obstacles with frame
	explicit Board(InitializeGame::Map cells, unsigned short width, unsigned short height);
	explicit Board(const Board& boardObject);
	virtual ~Board() { delete m_cells; }
	Board& operator=(const Board& boardObject);
	void createFruit();
	void setCell(const Position& cellPosition, CellStatus newStatus);
	CellStatus getCellStatus(Position cellPosition) const { return m_cells[cellPosition.x + cellPosition.y * m_width]; }
	const Position& getFruitPosition() const { return m_fruitPosition; }
	CellStatus& operator[](size_t i) { return m_cells[i]; }
	CellStatus operator[](size_t i) const { return m_cells[i]; }
	unsigned short getWidth() const { return m_width; }
	unsigned short getHeight() const { return m_height; }
private:
	CellStatus* m_cells;
	unsigned short m_width, m_height;
	Position m_fruitPosition;
};

#endif
