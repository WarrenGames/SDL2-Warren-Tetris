#ifndef ACCURATE_TIME_H
#define ACCURATE_TIME_H

#include <chrono>

class AccurateTimeDelay
{
private:
	std::chrono::steady_clock::time_point current;
	std::chrono::steady_clock::time_point precedent;
	std::chrono::duration<double, std::milli> duration;
	
public:
	explicit AccurateTimeDelay();
	AccurateTimeDelay( const AccurateTimeDelay& ) = default;
	AccurateTimeDelay&operator= ( const AccurateTimeDelay& ) = default;
	
	bool hasTimeElapsed(double passedTime);
	bool hasTimeNotElapsed(double delay);
	bool isTimeBetweenBoundaries(double min, double max);
	void joinTimePoints();
	void setPrecedentTimePoint();
	double getCurrentElapsedTime();
};

#endif //ACCURATE_TIME_H