#ifndef INIT_SDL2_COMPONENTS_H
#define INIT_SDL2_COMPONENTS_H

struct AppLogFiles;
class PrefPathFinder;

namespace initSDL2Comp{
	void context(AppLogFiles& logs, const PrefPathFinder& prefPath);
}

#endif //INIT_SDL2_COMPONENTS_H