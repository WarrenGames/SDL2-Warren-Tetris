#ifndef SCAN_LINES_INFOS_H
#define SCAN_LINES_INFOS_H

#include <cstddef>

struct ScanLinesInfos
{
	bool canScanToRemoveLines;
	std::size_t topLine;
	std::size_t bottomLine;
		   
	ScanLinesInfos();
	~ScanLinesInfos() = default;
	ScanLinesInfos( const ScanLinesInfos& ) = default;
	ScanLinesInfos& operator= ( const ScanLinesInfos& ) = default;
	ScanLinesInfos( ScanLinesInfos&& ) = default;
	ScanLinesInfos& operator= ( ScanLinesInfos&& ) = default;
};

#endif //SCAN_LINES_INFOS_H