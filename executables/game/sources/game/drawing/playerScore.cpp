#include "game/drawing/playerScore.h"
#include "logging/logsStruct.h"
#include "texturing/texturePosition.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "SDL.h"

PlayerScore::PlayerScore(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	canUpdateScore{false},
	score{0},
	font{logs.error, GameFontPath, 24},
	scoreTexture{logs, rndWnd, font, "Score: " + std::to_string(score), WhiteColor, TexturePosition{ (BigMatrixWidth + 4) * SQR_SIZE, 6 * SQR_SIZE, false, true} }
{
}

void PlayerScore::updateScoreText(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	if( canUpdateScore )
	{
		scoreTexture.texture.loadBlendedText(logs, rndWnd, font, "Score: " + std::to_string(score), WhiteColor); 
		scoreTexture.resetSpritePosition( TexturePosition{ (BigMatrixWidth + 4) * SQR_SIZE, 6 * SQR_SIZE, false, true} );
		canUpdateScore = false;
	}
}

void PlayerScore::addToScore(unsigned toAdd)
{
	score += toAdd;
	canUpdateScore = true;
}

void PlayerScore::drawScore(sdl2::RendererWindow& rndWnd) const
{
	scoreTexture.draw(rndWnd);
}

unsigned PlayerScore::getScore() const
{
	return score;
}