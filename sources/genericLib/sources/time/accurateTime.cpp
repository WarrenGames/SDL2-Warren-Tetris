#include "time/accurateTime.h"

AccurateTimeDelay::AccurateTimeDelay():
	current{std::chrono::steady_clock::now()},
	precedent{std::chrono::steady_clock::now()}
{
	
}

bool AccurateTimeDelay::hasTimeElapsed(double passedTime)
{
	current = std::chrono::steady_clock::now();
	
	duration = current - precedent;
	
	return duration.count() >= passedTime;
}

bool AccurateTimeDelay::hasTimeNotElapsed(double delay)
{
	current = std::chrono::steady_clock::now();

	duration = current - precedent;

	return duration.count() < delay;
}

bool AccurateTimeDelay::isTimeBetweenBoundaries(double min, double max)
{
	current = std::chrono::steady_clock::now();
	
	duration = current - precedent;
	
	return duration.count() >= min && duration.count() < max;
}

void AccurateTimeDelay::joinTimePoints()
{
	precedent = current;
}

void AccurateTimeDelay::setPrecedentTimePoint()
{
	precedent = std::chrono::steady_clock::now();
}

double AccurateTimeDelay::getCurrentElapsedTime()
{
	current = std::chrono::steady_clock::now();
	
	duration = current - precedent;
	
	return duration.count();
}