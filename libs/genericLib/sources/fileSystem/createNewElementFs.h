#ifndef CREATE_DIRECTORY_FS_H
#define CREATE_DIRECTORY_FS_H

#include <string>

enum{FS_NEW_CREATED, FS_NEW_EXIST, FS_NEW_ERROR, FS_NEW_MAX};

namespace createFs{

unsigned mkDirectoryIfMissing(const std::string& baseDir, const std::string& newDir);

unsigned mkNewFileIfMissing(const std::string& fileDirectory, const std::string& fileName);

unsigned mkNewFileIfMissing(const std::string& fileFullPath);

}

#endif //CREATE_DIRECTORY_FS_H