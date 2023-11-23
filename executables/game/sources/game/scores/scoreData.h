#ifndef SCORES_DATA_H
#define SCORES_DATA_H

#include "game/scores/scoresInfos.h"
#include "game/consts/constexpr.h"
#include <array>
#include <vector>
#include <string>

constexpr unsigned SCORE_NUM_PER_SKILL = 5;

struct Essentials;

class ScoresData
{
private:
	std::array< std::vector< Score >, GAME_MAX > scores;
	
public:
	explicit ScoresData(Essentials& essentials, unsigned playerScore, unsigned skill);
	~ScoresData() = default;
	ScoresData( const ScoresData& ) = delete;
	ScoresData& operator= ( const ScoresData& ) = delete;
	
	void loadScoreFile(Essentials& essentials, const std::string& scoreFilePath, unsigned skill);
	
	void outputScoresToFile(Essentials& essentials);
	void writeSingleFile(Essentials& essentials, const std::string& fileName, unsigned skill);
	
	void addCurrentPlayerScore(unsigned playerScore, unsigned skill);
	
	unsigned getScore(std::size_t skill, std::size_t scoreNum) const;
	bool isScoreFromRecentGame(std::size_t skill, std::size_t scoreNum) const;
	
	void sortVectors();
};

bool scoreIsGreater(const Score& first, const Score& second);

#endif //SCORES_DATA_H