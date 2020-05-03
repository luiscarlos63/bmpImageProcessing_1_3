#pragma once

#include <stdint.h>

class Header
{
public:
	Header();

	~Header();

	//metodos publicos



private:
	char Signature[2];
	uint32_t FileSize;
	uint32_t reserved;
	uint32_t DataOffset;
};

