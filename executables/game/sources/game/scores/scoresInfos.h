#ifndef SCORES_INFOS_H
#define SCORES_INFOS_H

struct Score
{
	unsigned playerScore;
	bool fromCurrentGame;
	
	Score();
	Score(unsigned playerScore, bool isNewScore);
};

#endif //SCORES_INFOS_H