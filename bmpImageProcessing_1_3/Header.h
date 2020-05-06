#pragma once

//lib includes
#include <iostream>
#include <stdint.h>
#include <fstream>

//my header includes

using namespace std;
//class Header

class Header
{
public:
	Header();

	~Header();

	//metodos publicos
	bool HeaderRead_f_File(ifstream& file);
	uint32_t get_DataOffset() { return this->DataOffset; }


private:
	char Signature[2];
	uint32_t FileSize;
	uint32_t reserved;
	uint32_t DataOffset;
};

