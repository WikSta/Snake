#ifndef INFORMATION_TEXTS_HPP
#define INFORMATION_TEXTS_HPP

#include <SFML/Graphics.hpp>
#include "ScoreText.hpp"
#include <cstddef>

class InformationTexts
{
public:
	sf::Text start;
	sf::Text pause;
	sf::Text win;
	sf::Text lose;
	ScoreText score;
	InformationTexts(unsigned int windowWidth, unsigned int windowHeight, const unsigned char* byteArray, size_t arrayLength);
	InformationTexts(unsigned int windowWidth, unsigned int windowHeight, const std::string& fontFileName);
private:
	sf::Font m_font;
	void InitializeTexts(unsigned int windowWidth, unsigned int windowHeight);
};

#endif
