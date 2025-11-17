#include "game/scores/scoreGraphics.h"
#include "texturing/texturePosition.h"
#include "game/scores/scoreData.h"
#include "commonFiles/types/essentials.h"
#include "game/consts/sdlColors.h"
#include <cassert>
#include <algorithm>
#include <fstream>

ScoresGraphics::ScoresGraphics(Essentials& essentials, const sdl2::Font& font, const ScoresData& data):
	title{essentials.logs, essentials.rndWnd, font, "Best scores", WhiteColor, TexturePosition{ GameWindowWidth / 2, SQR_SIZE, true, true} }
{	
	createTexts(essentials, font, data);
	addSkillText(essentials, font, "Easy", SkillEasyGame);
	addSkillText(essentials, font, "Intermediate", SkillIntermediateGame);
	addSkillText(essentials, font, "Hard", SkillHardGame);
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

void ScoresGraphics::createTexts(Essentials& essentials, const sdl2::Font& font, const ScoresData& data)
{
	for( std::size_t skill{0} ; skill < SkillGameMax ; ++skill )
	{
		for( std::size_t scoreNum{0} ; scoreNum < SCORE_NUM_PER_SKILL ; ++scoreNum )
		{
			scoresTexts[skill].emplace_back( TextureCombo{essentials.logs, essentials.rndWnd, font, 
												std::to_string(data.getScore(skill, scoreNum) ), getColor( data.isScoreFromRecentGame(skill, scoreNum) ), 
												TexturePosition{SQR_SIZE * 4, static_cast<int>(skill) * SQR_SIZE * 6 + static_cast<int>(scoreNum) * SQR_SIZE + SQR_SIZE * 4, false, true} } );
		}
	}
}

SDL_Color ScoresGraphics::getColor(bool isCurrentGame) const
{
	if( isCurrentGame )
		return GreenColor;
	else
		return WhiteColor;
}

void ScoresGraphics::addSkillText(Essentials& essentials, const sdl2::Font& font, const std::string& text, int skillNum)
{
	assert( skillNum < SkillGameMax );
	skillText.emplace_back(TextureCombo{essentials.logs, essentials.rndWnd, font, text, WhiteColor, TexturePosition{SQR_SIZE, skillNum * SQR_SIZE * 6 + SQR_SIZE * 3, false, true} } );
}