#include "game/scores/scoreGraphics.h"
#include "texturing/texturePosition.h"
#include "game/scores/scoreData.h"
#include "commonFiles/types/essentials.h"
#include "game/consts/sdlColors.h"
#include <cassert>
#include <algorithm>
#include <fstream>

ScoresGraphics::ScoresGraphics(Essentials& essentials, const sdl2::Font& arial, const ScoresData& data):
	title{essentials.logs, essentials.rndWnd, arial, "Best scores", WHITE_COL, TexturePosition{ SCREENW / 2, SQR_SIZE, true, true} }
{	
	createTexts(essentials, arial, data);
	addSkillText(essentials, arial, "Easy", EASY_GAME);
	addSkillText(essentials, arial, "Intermediate", INTERMEDIATE_GAME);
	addSkillText(essentials, arial, "Hard", HARD_GAME);
}

void ScoresGraphics::drawTexts(Essentials& essentials) const
{
	title.draw(essentials.rndWnd);
	drawSkillLevels(essentials);
	drawScores(essentials);
}

void ScoresGraphics::drawSkillLevels(Essentials& essentials) const
{
	for( auto const &text : skillText )
	{
		text.draw(essentials.rndWnd);
	}
}

void ScoresGraphics::drawScores(Essentials& essentials) const
{
	for( auto const &list : scoresTexts )
	{
		for( auto const &text : list )
		{
			text.draw(essentials.rndWnd);
		}
	}
}

void ScoresGraphics::createTexts(Essentials& essentials, const sdl2::Font& arial, const ScoresData& data)
{
	for( std::size_t skill{0} ; skill < GAME_MAX ; ++skill )
	{
		for( std::size_t scoreNum{0} ; scoreNum < SCORE_NUM_PER_SKILL ; ++scoreNum )
		{
			scoresTexts[skill].emplace_back( TextureCombo{essentials.logs, essentials.rndWnd, arial, 
												std::to_string(data.getScore(skill, scoreNum) ), getColor( data.isScoreFromRecentGame(skill, scoreNum) ), 
												TexturePosition{SQR_SIZE * 4, static_cast<int>(skill) * SQR_SIZE * 6 + static_cast<int>(scoreNum) * SQR_SIZE + SQR_SIZE * 4, false, true} } );
		}
	}
}

SDL_Color ScoresGraphics::getColor(bool isCurrentGame) const
{
	if( isCurrentGame )
		return GREEN_COL;
	else
		return WHITE_COL;
}

void ScoresGraphics::addSkillText(Essentials& essentials, const sdl2::Font& arial, const std::string& text, int skillNum)
{
	assert( skillNum < GAME_MAX );
	skillText.emplace_back(TextureCombo{essentials.logs, essentials.rndWnd, arial, text, WHITE_COL, TexturePosition{SQR_SIZE, skillNum * SQR_SIZE * 6 + SQR_SIZE * 3, false, true} } );
}