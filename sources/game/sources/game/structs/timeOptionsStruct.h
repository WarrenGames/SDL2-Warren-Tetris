#ifndef TIME_OPTIONS_STRUCT_H
#define TIME_OPTIONS_STRUCT_H

#include "time/accurateTime.h"

struct TimeOptions
{
	AccurateTimeDelay timePeriod;
	double fallDelay;
	double pieceFallTimeMin;
	double pieceFallTimeMax;
	double pieceSpeedIncr;
	double pieceFallTotalTime;
	double pieceFallChangeDelay;
	
	TimeOptions(double delay);
	
	void changePiecesSpeedIfAny();
	void setPieceFallChangeDelay();
};

#endif //TIME_OPTIONS_STRUCT_H