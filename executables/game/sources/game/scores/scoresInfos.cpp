#include "game/scores/scoresInfos.h"

Score::Score():
	playerScore{0},
	fromCurrentGame{false}
{
	
}

Score::Score(unsigned newScore, bool isNewScore):
	playerScore{newScore},
	fromCurrentGame{isNewScore}
{
	
}