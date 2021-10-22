#include "runGame/initialize/initSDL2Comp.h"
#include "logging/logsStruct.h"
#include "initialization/sdl2ModuleInit.h"
#include "initialization/sdl2TTF_Init.h"
#include "runGame/initialize/initRendWindow.h"

void initSDL2Comp::context(AppLogFiles& logs, const PrefPathFinder& prefPath)
{
	sdl2::ModuleInit sdl2Module{SDL_INIT_EVERYTHING, logs.error};
	sdl2::TTFModule ttfModule{logs.error};
	
	if( sdl2Module.wasLoadingPerfect() && ttfModule.wasLoadingPerfect() )
	{
		initRenderer::context(logs, prefPath);
	}
}