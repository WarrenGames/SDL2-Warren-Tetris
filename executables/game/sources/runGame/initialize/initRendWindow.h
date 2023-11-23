#ifndef INITIALIZE_RENDERER_WINDOWS_H
#define INITIALIZE_RENDERER_WINDOWS_H

struct AppLogFiles;
class PrefPathFinder;

namespace initRenderer{
	void context(AppLogFiles& logs, const PrefPathFinder& prefPath);
}

#endif //INITIALIZE_RENDERER_WINDOWS_H