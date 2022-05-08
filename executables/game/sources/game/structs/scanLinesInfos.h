#ifndef SCAN_LINES_INFOS_H
#define SCAN_LINES_INFOS_H

#include <cstddef>

struct ScanLinesInfos
{
	bool canScanToRemoveLines;
	std::size_t topLine;
	std::size_t bottomLine;
		   
	ScanLinesInfos();
};

#endif //SCAN_LINES_INFOS_H