#include "game/structs/timeOptionsStruct.h"

TimeOptions::TimeOptions(double delay):
	timePeriod{},
	fallDelay{delay},
	pieceFallTimeMin{100},
	pieceFallTimeMax{1000},
	pieceSpeedIncr{1},
	pieceFallTotalTime{1000 * 60 * 15},	
	pieceFallChangeDelay{ 1000 * pieceFallTotalTime / ( pieceFallTimeMax - pieceFallTimeMin) / pieceSpeedIncr}
{
	
}

void TimeOptions::changePiecesSpeedIfAny()
{
	if( timePeriod.hasTimeElapsed( std::chrono::microseconds{pieceFallChangeDelay} ) )
	{
		if( fallDelay >= pieceFallTimeMin + pieceSpeedIncr && fallDelay <= pieceFallTimeMax )
		{
			fallDelay -= pieceSpeedIncr;
		}
		timePeriod.joinTimePoints();
	}
}

void TimeOptions::setPieceFallChangeDelay()
{
	pieceFallChangeDelay = 1000 * pieceFallTotalTime / ( pieceFallTimeMax - pieceFallTimeMin ) / pieceSpeedIncr;
}