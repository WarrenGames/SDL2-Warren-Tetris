#include "game/objects/chronoTimer.h"
#include "commonFiles/types/essentials.h"
#include "texturing/texturePosition.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "game/consts/fontsSizes.h"

ChronoTimer::ChronoTimer(Essentials& essentials):
	arial{essentials.logs.error, GameFontPath, FontMediumSize},
	chrono{},
	elapsedMinutes{0},
	elapsedSeconds{0},
	chronoGraphicalText{essentials.logs, essentials.rndWnd, arial, getText(), WhiteColor, TexturePosition{GameWindowWidth / 2 + SQR_SIZE, SQR_SIZE * 8, false, true} },
	doesTextNeedChange{false}
{
	
}

std::string ChronoTimer::getText() const
{
	return std::string{ std::to_string(elapsedMinutes) + " minutes and " + std::to_string( elapsedSeconds ) + " seconds."};
}

void ChronoTimer::changeGraphicalTextIfNeeded(Essentials& essentials)
{
	if( doesTextNeedChange )
	{
		chronoGraphicalText.texture.loadBlendedText(essentials.logs, essentials.rndWnd, arial, getText(), WhiteColor);
		chronoGraphicalText.resetSpritePosition(TexturePosition{GameWindowWidth/2+SQR_SIZE, SQR_SIZE*8, false, true} );
		doesTextNeedChange = false;
	}
}

void ChronoTimer::drawText(Essentials& essentials) const
{
	chronoGraphicalText.draw(essentials.rndWnd);
}

void ChronoTimer::mesureElapsedTime()
{
	if( chrono.hasTimeElapsed( std::chrono::milliseconds{1000} ) )
	{
		doesTextNeedChange = true;
		elapsedSeconds++;
		
		if( elapsedSeconds >= 60 )
		{
			elapsedMinutes++;
			elapsedSeconds -= 60;
		}
		chrono.joinTimePoints();
	}
}