#include "game/structs/timeOptionsStruct.h"

TimeOptions::TimeOptions(double delay):
	timePeriod{},
	fallDelay{delay},
	pieceFallTimeMin{100},
	pieceFallTimeMax{1000},
	pieceSpeedIncr{1},
	pieceFallTotalTime{1000 * 60 * 15},	
	pieceFallChangeDelay{pieceFallTotalTime / ( pieceFallTimeMax - pieceFallTimeMin) / pieceSpeedIncr}
{
	
}

void TimeOptions::changePiecesSpeedIfAny()
{
	if( timePeriod.hasTimeElapsed(pieceFallChangeDelay) )
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
	pieceFallChangeDelay = pieceFallTotalTime / ( pieceFallTimeMax - pieceFallTimeMin ) / pieceSpeedIncr;
}