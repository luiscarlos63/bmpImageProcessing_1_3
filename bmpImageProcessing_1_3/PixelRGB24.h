#pragma once

#include <stdint.h>

class PixelRGB24
{
	PixelRGB24();
	PixelRGB24(uint8_t, uint8_t, uint8_t);
	PixelRGB24(const PixelRGB24&);
	//~PixelRGB24();

	void setPixel(uint8_t, uint8_t, uint8_t);
	void setPixel(const PixelRGB24& );

	//
	

private:
	uint8_t Blue;
	uint8_t Green;
	uint8_t Red;
};

