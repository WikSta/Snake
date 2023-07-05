#ifndef SCORE_TEXT_HPP
#define SCORE_TEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class ScoreText : public sf::Text
{
public:
	enum Limits { MAX_SCORE = 999 };

	ScoreText();
	bool setScore(unsigned short score);
private:
	std::string m_score;
};

#endif