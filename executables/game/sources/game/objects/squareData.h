#ifndef SQUARE_DATA_STRUCT_H
#define SQUARE_DATA_STRUCT_H

#include <cstdlib>

struct SquareData
{
	std::size_t color;
	bool filled;
	
	SquareData();
	~SquareData() = default;
	SquareData( const SquareData& ) = default;
	SquareData& operator= ( const SquareData& ) = default;
	SquareData( SquareData&& ) = default;
	SquareData& operator= ( SquareData&& ) = default;
};

#endif //SQUARE_DATA_STRUCT_H