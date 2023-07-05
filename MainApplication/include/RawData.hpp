#ifndef RAW_DATA_HPP
#define RAW_DATA_HPP
#include <cstddef>

namespace rawdata
{
	extern const size_t ARIAL_FONT_BYTES_ARRAY_LENGTH;
	extern const unsigned char ARIAL_FONT_BYTES_ARRAY[];

	enum PixelSizes { TILE_PIXELS_X = 40, TILE_PIXELS_Y = 40, IMAGE_PIXELS_X = 680, IMAGE_PIXELS_Y = 40};
	extern const size_t TILESET_IMAGE_BYTES_ARRAY_LENGTH;
	extern const unsigned char TILESET_IMAGE_BYTES_ARRAY[];
}

#endif
