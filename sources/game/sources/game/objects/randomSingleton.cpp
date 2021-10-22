#include "game/objects/randomSingleton.h"
#include <cassert>
#include <ctime>

RandomSingleton::RandomSingleton(std::vector<Difference> DistribValues):
	e1{static_cast<unsigned>(std::time(nullptr))}
{
	assert( DistribValues.size() > 0 );
	
	for( auto const &it : DistribValues )
	{
		distributions.push_back(std::uniform_int_distribution<int>{it.startPoint, it.endPoint});
	}
}

unsigned RandomSingleton::getRandomNumber(size_t distribIndex)
{
	assert( distribIndex < distributions.size() );
	
	return distributions[distribIndex](e1);
}