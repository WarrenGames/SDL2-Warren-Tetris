#ifndef LOGS_STRUCTS_H
#define LOGS_STRUCTS_H

#include "logging/logFile.h"

struct AppLogFiles
{
	LogFile error;
	LogFile warning;
	
	explicit AppLogFiles(const std::string& path, const std::string& errFile, const std::string& warnFile);
	~AppLogFiles() = default;
	AppLogFiles( const AppLogFiles& ) = delete;
	AppLogFiles& operator= ( const AppLogFiles& ) = delete;
	AppLogFiles( AppLogFiles&& ) = default;
	AppLogFiles& operator= ( AppLogFiles&& ) = default;
	
	operator bool() const;
};

#endif //LOGS_STRUCTS_H