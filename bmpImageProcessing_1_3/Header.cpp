#include "Header.h"


using namespace std;

Header::Header()
	//:Signature(" "), FileSize(0), reserved(0), DataOffset(64)
{
	

}

Header::~Header()
{
}

bool Header::HeaderRead_f_File(ifstream& file)
{
	Header hdr;

	try 
	{
		if (file.fail())
			throw("Header Error: HeaderRead_f_File, file.fail()");

		if (!file.read((char*)&hdr.Signature, 2))
			throw("Header Error: HeaderRead_f_File, file.read()_Signature");


		if (!file.read((char*)&hdr.FileSize, sizeof(FileSize)))
			throw("Header Error: HeaderRead_f_File, file.read()_FileSize");

		if (!file.read((char*)&hdr.reserved, sizeof(reserved)))
			throw("Header Error: HeaderRead_f_File, file.read()_reserved");

		if (!file.read((char*)&hdr.DataOffset, sizeof(DataOffset)))
			throw("Header Error: HeaderRead_f_File, file.read()_DataOffset");

	}catch (const char* str_err)
		{
			cout << str_err;
			return false;
		}

	*this = hdr;
								//cout << hdr.Signature << "	" << hdr.FileSize << " " << hdr.reserved << "	" << hdr.DataOffset;
	return true;
}
