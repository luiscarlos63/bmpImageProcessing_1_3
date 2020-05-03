#pragma once

#include <stdint.h>



class InfoHeader
{
public:
	

private:
	uint32_t size;
	uint32_t width;
	uint32_t heith;
	uint16_t planes;
	uint16_t bitsPpixel;
	uint32_t compression;
	uint32_t XpixelsPerM;
	uint32_t YpixelsPerM;
	uint32_t colorsUsed;
	uint32_t ImportantColors;

//	uint32_t ColorTable;	//ainda nao tenho certeza como lidar com isto
};

