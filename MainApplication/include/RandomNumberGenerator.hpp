#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

#include <ctime>
#include <cstdlib>

class RandomNumberGenerator
{
public:
	explicit RandomNumberGenerator() { srand(m_seed); }
	int  generateNumber(int min, int max) const { return min + (rand() % (max - min)); }
private:
	time_t m_seed = time(0);
};

#endif
