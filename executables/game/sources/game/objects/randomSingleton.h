#ifndef RANDOM_SINGLETON_H
#define RANDOM_SINGLETON_H

#include <random>
#include <vector>

struct Difference
{
	int startPoint;
	int	endPoint;
};

class RandomSingleton
{
private:
	std::default_random_engine e1;
	
	std::vector<std::uniform_int_distribution<int> > distributions;

public:
	RandomSingleton(std::vector<Difference> DistribValues);
	RandomSingleton() = delete;
	~RandomSingleton() = default;
	
	unsigned getRandomNumber(std::size_t distribIndex);
};

#endif //RANDOM_SINGLETON_H