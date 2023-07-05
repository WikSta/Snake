#include "InformationTexts.hpp"

InformationTexts::InformationTexts(unsigned int windowWidth, unsigned int windowHeight, const unsigned char* byteArray, size_t arrayLength ) 
{
	m_font.loadFromMemory(byteArray, arrayLength);
	InitializeTexts(windowWidth, windowHeight);
}

InformationTexts::InformationTexts(unsigned int windowWidth, unsigned int windowHeight, const std::string& fontFileName)
{
	m_font.loadFromFile(fontFileName);
	InitializeTexts(windowWidth, windowHeight);
}

// private methods
void InformationTexts::InitializeTexts(unsigned int windowWidth, unsigned int windowHeight)
{
	// set Font
	start.setFont(m_font);
	pause.setFont(m_font);
	win.setFont(m_font);
	lose.setFont(m_font);
	score.setFont(m_font);
	// set strings
	start.setString("Welcome to the snake Game\nUse arrow keys to control snake movement\nSpacebar is used to pause the game\nPress any key to start");
	pause.setString("Game is Paused\nPress Space to resume");
	win.setString("You won\nPress a button to exit");
	lose.setString("You lost\nPress a button to exit");
	// set position in the centre
	sf::FloatRect textBox;
	textBox = start.getGlobalBounds();
	start.setPosition(sf::Vector2f((windowWidth - textBox.width) / 2.f, (windowHeight - textBox.height) / 2.f));
	textBox = pause.getGlobalBounds();
	pause.setPosition(sf::Vector2f((windowWidth - textBox.width) / 2.f, (windowHeight - textBox.height) / 2.f));
	textBox = win.getGlobalBounds();
	win.setPosition(sf::Vector2f((windowWidth - textBox.width) / 2.f, (windowHeight - textBox.height) / 2.f));
	textBox = lose.getGlobalBounds();
	lose.setPosition(sf::Vector2f((windowWidth - textBox.width) / 2.f, (windowHeight - textBox.height) / 2.f));
}