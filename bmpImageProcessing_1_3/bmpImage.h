#pragma once

#include <vector>

#include "Header.h"
#include "InfoHeader.h"
#include "PixelRGB24.h"

using namespace std;

class bmpImage 
{
	bmpImage();
	~bmpImage();

	//metodos de aplicaçao de filtros


private:
	Header	header;
	InfoHeader infoheadr;
	vector<PixelRGB24> PixelData;		
};

