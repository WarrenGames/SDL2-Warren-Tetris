#ifndef ESSENTIALS_STRUCT_H
#define ESSENTIALS_STRUCT_H

#include "logging/logsStruct.h"
#include "prefPath/prefPathFinder.h"
#include "texturing/rendererWindow.h"
#include "game/input/userInput.h"
#include "time/accurateTime.h"

struct Essentials
{
	const PrefPathFinder& prefPath;
	AppLogFiles& logs;
	sdl2::RendererWindow& rndWnd;
	UserInput inp;
	AccurateTimeDelay drawFrequency;
	
	explicit Essentials(AppLogFiles& logs_, const PrefPathFinder& prefPath_, sdl2::RendererWindow& rndWnd_);
	~Essentials() = default;
	Essentials( const Essentials& ) = delete;
	Essentials& operator= ( const Essentials& ) = delete;
	Essentials( Essentials&& ) = delete;
	Essentials& operator= ( Essentials&& ) = delete;
};

#endif //ESSENTIALS_STRUCT_H