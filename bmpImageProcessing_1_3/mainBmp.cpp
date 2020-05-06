#include <iostream>
#include <fstream>
#include <string>

#include <stdint.h>

//header files Includes
#include "Header.h"
#include "InfoHeader.h"
#include "PixelRGB24.h"
#include "bmpImage.h"


//Private defines
#define sampleFileName "sample.bmp"
#define my_experFileName "exper.txt"

using namespace std;


//function Prototypes


int main()
{

		ifstream my_file;
		Header header;
		InfoHeader info;

		my_file.open(sampleFileName);
		cout << my_file.tellg() << endl;
		header.HeaderRead_f_File(my_file);
		cout << my_file.tellg() << endl;
		info.InfoHeaderRead_f_File(my_file);
		cout << my_file.tellg() << endl;
		
		cout << "ora boas";
	return 0;
}



