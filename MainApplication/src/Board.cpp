#include "Board.hpp"
#include "RandomNumberGenerator.hpp"
#include <stdexcept>

Board::Board(InitializeGame::Map cells, unsigned short width, unsigned short height) : m_width(width), m_height(height)
{
	m_cells = new CellStatus[width * height];
	for (size_t i = 0; i < width; ++i)
		for (size_t j = 0; j < height; ++j)
			m_cells[i + j * width] = CellStatus(cells[i + j * width]);
}

Board::Board(unsigned short width, unsigned short height) : m_width(width), m_height(height)
{
	m_cells = new CellStatus[width * height];
	size_t i, j;
	for (i = 0; i < width; ++i)													// 1 1 1 . . 1 1 WIDTH X HEIGHT
		for (j = 0; j < height; ++j)											// 1 0 0 . . 0 1 
			m_cells[i + j * width] = EMPTY;										// 1 0 0 . . 0 1
	for (i = 0; i < height; ++i)												// . . . . . . .
		m_cells[0 + i * width] = m_cells[size_t(width) - 1 + i * width] = BORDER;       // . . . . . . .
	for (i = 0; i < width; ++i)                                                 // 1 0 0 . . 0 1
		m_cells[i + 0] = m_cells[i + (size_t(height) - 1) * width] = BORDER;    // 1 1 1 . . 1 1
}

Board::Board(const Board& boardObject)
{
	m_width = boardObject.m_width;
	m_height = boardObject.m_height;
	m_cells = new CellStatus[m_width * m_height];
	m_fruitPosition = boardObject.getFruitPosition();
	for (size_t i = 0; i < m_width; ++i)
		for (size_t j = 0; j < m_height; ++j)
			m_cells[i + j * m_width] = boardObject.m_cells[i + j * m_width];
}

Board& Board::operator=(const Board& boardObject)
{
	if (&boardObject == this)
		return *this;
	m_width = boardObject.m_width;
	m_height = boardObject.m_height;
	delete m_cells;
	m_cells = new CellStatus[m_width * m_height];
	m_fruitPosition = boardObject.getFruitPosition();
	for (size_t i = 0; i < m_width; ++i)
		for (size_t j = 0; j < m_height; ++j)
			m_cells[i + j * m_width] = boardObject.m_cells[i + j * m_width];

	return *this;
}

void Board::createFruit()
{
	RandomNumberGenerator rng;

	do
	{
		m_fruitPosition.x = rng.generateNumber(0, m_width);
		m_fruitPosition.y = rng.generateNumber(0, m_height);
	} while (getCellStatus(m_fruitPosition));
	setCell(m_fruitPosition, FRUIT);
}

void Board::setCell(const Position& cellPosition, CellStatus newStatus)
{
	if (cellPosition.x >= m_width || cellPosition.y >= m_height)
		throw std::invalid_argument("Position of the altered cell musnt not go beyond the board!");
	if (cellPosition.x < 0 || cellPosition.y < 0)
		throw std::invalid_argument("Position of the altered cell must be non-negative!");
	m_cells[cellPosition.x + cellPosition.y * m_width] = newStatus;
}