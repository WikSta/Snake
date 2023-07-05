#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Snake.hpp"
#include "Board.hpp"
#include "SnakeGame.hpp"
#include "TileMap.hpp"
#include "InformationTexts.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "RawData.hpp"

class Application
{
public:
	explicit Application();
	void run();
private:
	enum WindowSize { WINDOW_WIDTH = InitializeGame::BOARD_WIDTH * rawdata::TILE_PIXELS_X, 
		WINDOW_HEIGHT = InitializeGame::BOARD_HEIGHT * rawdata::TILE_PIXELS_Y };
	enum TickTime { TICK_TIME_MS = 300 };

	SnakeGame::GameResult result;
	// model
	Snake m_snake;
	Board m_board;
	// logic
	SnakeGame m_gameLogic;
	// View
	InformationTexts m_texts;
	TileMap m_tileMap;
	// utilities
	sf::Event m_event;
	const sf::Time m_timeOfOneTcik;
	sf::Clock m_stoper;
	// window
	sf::RenderWindow m_mainWindow;
	// private methods
	void display(const sf::Drawable& objectToDraw);
	void handleEvents();
	void keyCodeToControls();
	void waitForKeyPress(const sf::Drawable& objectToDraw);
};

#endif
