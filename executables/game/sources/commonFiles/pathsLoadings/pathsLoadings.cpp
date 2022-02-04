#include "commonFiles/pathsLoadings/pathsLoadings.h"
#include "prefPath/prefPathFinder.h"

std::string paths::getKeycodesControl(const PrefPathFinder& prefPath)
{
	return std::string{ prefPath.getPath() + "keycodesConfig.ini" };
}