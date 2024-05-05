#include "game/scores/scoreData.h"
#include "commonFiles/types/essentials.h"
#include <algorithm>
#include <fstream>
#include <cassert>

ScoresData::ScoresData(Essentials& essentials, unsigned playerScore, unsigned skill):
	scores{
		std::vector<Score>(SCORE_NUM_PER_SKILL),
		std::vector<Score>(SCORE_NUM_PER_SKILL),
		std::vector<Score>(SCORE_NUM_PER_SKILL)
	}
{
	loadScoreFile(essentials, essentials.prefPath.getPath() + EASY_FILE_NAME, EASY_GAME);
	loadScoreFile(essentials, essentials.prefPath.getPath() + INTERM_FILE_NAME, INTERMEDIATE_GAME);
	loadScoreFile(essentials, essentials.prefPath.getPath() + HARD_FILE_NAME, HARD_GAME);
	addCurrentPlayerScore(playerScore, skill);
	sortVectors();
}

void ScoresData::loadScoreFile(Essentials& essentials, const std::string& scoreFilePath, unsigned skill)
{
	assert( skill < GAME_MAX );
	if( std::ifstream scoreFile{scoreFilePath} )
	{
		for( std::size_t i{0} ; i < SCORE_NUM_PER_SKILL ; ++i )
		{
			if(  scoreFile >> scores[skill][i].playerScore )
			{
				scores[skill][i].fromCurrentGame = false;
			}
			else
			{
				essentials.logs.error << "Error: couldn't read all the scores data.\n";
			}
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open file '" << scoreFilePath << "' to load score of skill number #" << skill << " .\n"; 
	}
}

void ScoresData::outputScoresToFile(Essentials& essentials)
{
	writeSingleFile(essentials, EASY_FILE_NAME, 0);
	writeSingleFile(essentials, INTERM_FILE_NAME, 1);
	writeSingleFile(essentials, HARD_FILE_NAME, 2);
}

void ScoresData::writeSingleFile(Essentials& essentials, const std::string& fileName, unsigned skill)
{
	if( std::ofstream bestScoreFile{essentials.prefPath.getPath() + fileName} )
	{
		for( std::size_t i{0} ; i < SCORE_NUM_PER_SKILL - 1 ; ++i )
		{
			bestScoreFile << scores[skill][i].playerScore << " ";
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open file '" << essentials.prefPath.getPath() << fileName << " to write best scores data.\n";
	}
}

void ScoresData::addCurrentPlayerScore(unsigned playerScore, unsigned skill)
{
	assert( skill < scores.size() );
	scores[skill].emplace_back(Score{playerScore, true} );
}

unsigned ScoresData::getScore(std::size_t skill, std::size_t scoreNum) const
{
	assert( skill < scores.size() );
	assert( scoreNum < SCORE_NUM_PER_SKILL);
	return scores[skill][scoreNum].playerScore;
}

bool ScoresData::isScoreFromRecentGame(std::size_t skill, std::size_t scoreNum) const
{
	assert( skill < scores.size() );
	assert( scoreNum < SCORE_NUM_PER_SKILL);
	return scores[skill][scoreNum].fromCurrentGame;
}

void ScoresData::sortVectors()
{
	for( auto &skillArray : scores )
		std::sort(skillArray.begin(), skillArray.end(), scoreIsGreater );
}

bool scoreIsGreater(const Score& first, const Score& second)
{
	return first.playerScore >= second.playerScore;
}