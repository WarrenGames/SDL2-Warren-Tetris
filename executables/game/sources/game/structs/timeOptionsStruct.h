#ifndef TIME_OPTIONS_STRUCT_H
#define TIME_OPTIONS_STRUCT_H

#include "time/accurateTime.h"

struct TimeOptions
{
	AccurateTimeDelay timePeriod;
	double fallDelay;
	unsigned pieceFallTimeMin;
	unsigned pieceFallTimeMax;
	unsigned pieceSpeedIncr;
	unsigned pieceFallTotalTime;
	unsigned pieceFallChangeDelay;
	
	TimeOptions(double delay);
	~TimeOptions() = default;
	TimeOptions( const TimeOptions& ) = default;
	TimeOptions& operator= ( const TimeOptions& ) = default;
	TimeOptions( TimeOptions&& ) = default;
	TimeOptions& operator= ( TimeOptions&& ) = default;
	
	void changePiecesSpeedIfAny();
	void setPieceFallChangeDelay();
};

#endif //TIME_OPTIONS_STRUCT_H