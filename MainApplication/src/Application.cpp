#include "Application.hpp"

Application::Application() : 
    m_snake(InitializeGame::createSnake(), Snake::RIGHT),
    m_board(InitializeGame::createBoard(), InitializeGame::BOARD_WIDTH, InitializeGame::BOARD_HEIGHT),
    m_gameLogic(m_snake, m_board),
    m_tileMap(m_board, rawdata::TILESET_IMAGE_BYTES_ARRAY, 
        sf::Vector2u(rawdata::IMAGE_PIXELS_X, rawdata::IMAGE_PIXELS_Y), // size of image
        sf::Vector2u(rawdata::TILE_PIXELS_X, rawdata::TILE_PIXELS_Y)), // size of tile
    m_mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake"),
    m_timeOfOneTcik(sf::milliseconds(TICK_TIME_MS)),
    m_texts(WINDOW_WIDTH, WINDOW_HEIGHT, rawdata::ALICE_FONT_BYTES_ARRAY, rawdata::ALICE_FONT_BYTES_ARRAY_LENGTH)
{
    result = SnakeGame::CONTINUE;
    m_mainWindow.setKeyRepeatEnabled(false);
    m_mainWindow.setFramerateLimit(60);
}

void Application::run()
{
    m_tileMap.updateQuads();
    waitForKeyPress(m_texts.start);
	while (m_mainWindow.isOpen())
	{
        if (m_stoper.getElapsedTime() >= m_timeOfOneTcik)
        {
            if (result = m_gameLogic.tick())
            {
                m_texts.score.setScore(m_gameLogic.getScore());
                switch (result)
                {
                    case SnakeGame::WIN :
                        waitForKeyPress(m_texts.win);
                    case SnakeGame::LOSE :
                        waitForKeyPress(m_texts.lose);
                }
                m_mainWindow.close();
            }
            m_tileMap.updateQuads();
            m_texts.score.setScore(m_gameLogic.getScore());
            m_stoper.restart();
        }
        handleEvents();
        if (m_gameLogic.isPaused())
            display(m_texts.pause);
        else
            display(m_tileMap);
	}
}

// private methods
void Application::handleEvents()
{
    while (m_mainWindow.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
            m_mainWindow.close();
        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Space)
                m_gameLogic.isPaused() ? m_gameLogic.resume() : m_gameLogic.pause();
            else
                keyCodeToControls();
        }
    }
}

void Application::display(const sf::Drawable& objectToDraw)
{
    m_mainWindow.clear();
    m_mainWindow.draw(objectToDraw);
    m_mainWindow.draw(m_texts.score);
    m_mainWindow.display();
}

void Application::keyCodeToControls()
{
    switch (m_event.key.code)
    {
    case sf::Keyboard::Up:
        m_gameLogic.takeInput(SnakeGame::MOVE_UP);
    case sf::Keyboard::Down:
        m_gameLogic.takeInput(SnakeGame::MOVE_DOWN);
        break;
    case sf::Keyboard::Left:
        m_gameLogic.takeInput(SnakeGame::MOVE_LEFT);
        break;
    case sf::Keyboard::Right:
        m_gameLogic.takeInput(SnakeGame::MOVE_RIGHT);
        break;
    }
}

void Application::waitForKeyPress(const sf::Drawable& objectToDraw)
{
    bool keyPressed = false;
    while (m_mainWindow.isOpen() && !keyPressed)
    {
        while (m_mainWindow.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
                m_mainWindow.close();
            if (m_event.type == sf::Event::KeyPressed)
                keyPressed = true;
        }
        display(objectToDraw);
    }
}