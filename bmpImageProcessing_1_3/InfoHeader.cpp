#include "InfoHeader.h"


InfoHeader::InfoHeader()
	:size(RSETVALUE), width(RSETVALUE), heith(RSETVALUE), planes(RSETVALUE),
		bitsPpixel(RSETVALUE), compression(RSETVALUE), XpixelsPerM(RSETVALUE),
			YpixelsPerM(RSETVALUE), colorsUsed(RSETVALUE), ImportantColors(RSETVALUE)
{
}

InfoHeader::InfoHeader(const InfoHeader& iHdr_cpy)
{
	*this = iHdr_cpy;
}

/*
*LER O INFOHEADER
*/
bool InfoHeader::InfoHeaderRead_f_File(ifstream & file)
{
	InfoHeader iHdr;

	try
	{
		if (file.fail())
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.fail()");
			
		if (file.tellg() != INFOHRDIOFFSET)	//verifica se o "index de leitura do ficheiro" se encontra na posiçao certa (0x0E)
			throw("InfoHeader Error: InfoHeaderRead_f_File, info header OFFSET != 0x0E");

		//leitura dos parâmetros
		if (!file.read((char*)&iHdr.size, sizeof(size)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_size");

		if (!file.read((char*)&iHdr.width, sizeof(width)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_width");

		if (!file.read((char*)&iHdr.heith, sizeof(heith)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_heith");

		if (!file.read((char*)&iHdr.planes, sizeof(planes)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_planes");

		if (!file.read((char*)&iHdr.bitsPpixel, sizeof(bitsPpixel)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_bitsPpixel");

		if (!file.read((char*)&iHdr.compression, sizeof(compression)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_compression");

		if (!file.read((char*)&iHdr.ImageSize, sizeof(ImageSize)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_ImageSize");

		if (!file.read((char*)&iHdr.XpixelsPerM, sizeof(XpixelsPerM)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_XpixelsPerM");

		if (!file.read((char*)&iHdr.YpixelsPerM, sizeof(YpixelsPerM)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_YpixelsPerM");

		if (!file.read((char*)&iHdr.colorsUsed, sizeof(colorsUsed)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_colorsUsed");

		if (!file.read((char*)&iHdr.ImportantColors, sizeof(ImportantColors)))
			throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_ImportantColors");
	}
	catch (const char* str_err)
	{
		cout << str_err;
		return false;
	}

	*this = iHdr;	//atribuir a informaçao lida e validada

	return true;
}
