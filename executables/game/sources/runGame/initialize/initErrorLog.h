#ifndef INIT_ERROR_LOG_H
#define INIT_ERROR_LOG_H

class PrefPathFinder;

namespace initLogs{
	void initPrefPath();
	
	void openLogFile(const PrefPathFinder& prefPath);
}

#endif //INIT_ERROR_LOG_H