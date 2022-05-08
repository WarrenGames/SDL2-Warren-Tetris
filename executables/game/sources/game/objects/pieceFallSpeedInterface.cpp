#include "game/objects/pieceFallSpeedInterface.h"
#include "commonFiles/types/essentials.h"
#include "texturing/texturePosition.h"
#include "game/structs/timeOptionsStruct.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "game/consts/fontsSizes.h"

SpeedInterface::SpeedInterface(Essentials& essentials, const TimeOptions& timeOptions):
	arial{essentials.logs.error, ARIALFONTPATH, FONT_MEDIUM_SIZE},
	speed{timeOptions.fallDelay}, 
	speedText{essentials.logs, essentials.rndWnd, arial, "Speed: " + std::to_string( 1 / timeOptions.fallDelay ), WHITE_COL, TexturePosition{SCREENW / 2 + SQR_SIZE, SQR_SIZE * 10, false, true} }
{
	
}

void SpeedInterface::resetText(Essentials& essentials, const TimeOptions& timeOptions)
{
	if( timeOptions.fallDelay != speed )
	{
		speed = timeOptions.fallDelay;
		speedText.texture.loadBlendedText(essentials.logs, essentials.rndWnd, arial, "Speed: " + std::to_string(1 / speed), WHITE_COL);
		speedText.resetSpritePosition( TexturePosition{SCREENW / 2 + SQR_SIZE, SQR_SIZE * 10, false, true } );
	}
}

void SpeedInterface::drawSpeedText(Essentials& essentials) const
{
	speedText.draw(essentials.rndWnd);
}