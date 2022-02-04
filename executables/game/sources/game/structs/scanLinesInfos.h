#ifndef SCAN_LINES_INFOS_H
#define SCAN_LINES_INFOS_H

#include <cstddef>

struct ScanLinesInfos
{
	bool canScanToRemoveLines;
	size_t topLine;
	size_t bottomLine;
		   
	ScanLinesInfos();
};

#endif //SCAN_LINES_INFOS_H