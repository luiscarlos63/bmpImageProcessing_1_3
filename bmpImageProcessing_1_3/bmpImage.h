#pragma once

//lib includes
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <vector>

//my header includes
#include "Header.h"
#include "InfoHeader.h"
#include "PixelRGB24.h"

//my defines


using namespace std;

//class bmpImage
class bmpImage 
{
	bmpImage();
	~bmpImage();

	//metodos de aplicaçao de filtros
	bool ImageRead_f_File(const char*);
	bool PixelDataRead_f_File(ifstream&);

private:
	Header	header;
	InfoHeader infoheader;
	//COLOR TABLE: "uint32_t"  (neste caso = 0x00000000) //ignorar por agora
	vector<PixelRGB24> PixelData;		
};

