#include "logging/logsStruct.h"

AppLogFiles::AppLogFiles(const std::string& path, const std::string& errFile, const std::string& warnFile):
	error{ path, errFile, "Error: "},
	warning{ path, warnFile, "Warning: "}
{

}

AppLogFiles::operator bool() const
{
	return error && warning;
}