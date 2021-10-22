#include "random/randomGenerator.h"
#include <chrono>

IntRandomGenerator::IntRandomGenerator(int lowValue, int highValue):
	mersenne{ static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) },
	integers{ lowValue, highValue }
{
	
}

int IntRandomGenerator::getRandomValue()
{
	return integers( mersenne );
}