#ifndef COPY_EDIT_KYS_CONFIG_H
#define COPY_EDIT_KYS_CONFIG_H

#include <string>

class LogFile;

enum{FS_COPY_CREATED, FS_COPY_EXIST, FS_COPY_ERROR, FS_COPY_MAX};

namespace copyFs{

unsigned fileWithLogNoErase(LogFile& log, const std::string& srcFilePath, const std::string& destFilePath);

void directoriesRecursively(LogFile& log, const std::string& srcPath, const std::string& destPath);

}
#endif //COPY_EDIT_KYS_CONFIG_H