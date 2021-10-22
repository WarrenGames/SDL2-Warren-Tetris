#ifndef TEMPLATE_MATRIX_STRUCTS_H
#define TEMPLATE_MATRIX_STRUCTS_H

#include <cstddef>

struct Coord3D
{
	size_t width;
	size_t height;
	size_t depth;
	
	Coord3D();
	Coord3D(size_t w, size_t h, size_t d);
};

struct Coord2D
{
	size_t width;
	size_t height;
	
	Coord2D();
	Coord2D(size_t w, size_t h);
};

#endif //TEMPLATE_MATRIX_STRUCTS_H