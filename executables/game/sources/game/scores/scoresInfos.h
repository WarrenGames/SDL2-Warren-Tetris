#ifndef SCORES_INFOS_H
#define SCORES_INFOS_H

struct Score
{
	unsigned playerScore;
	bool fromCurrentGame;
	
	Score();
	Score(unsigned playerScore, bool isNewScore);
	~Score() = default;
	Score( const Score& ) = default;
	Score& operator= ( const Score& ) = default;
	Score( Score&& ) = default;
	Score& operator= ( Score&& ) = default;
};

#endif //SCORES_INFOS_H