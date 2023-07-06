#include "ScoreText.hpp"

ScoreText::ScoreText()
{
	setString(std::string("score: ") + std::to_string(0)); // convert 0 to string
}

bool ScoreText::setScore(unsigned short score)
{
	if (score > MAX_SCORE)
		return false;
	setString(std::string("score: ") + std::to_string(score)); // convert score to string
	return true;
}