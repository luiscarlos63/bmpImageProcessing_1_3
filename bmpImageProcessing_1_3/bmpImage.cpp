#include "bmpImage.h"

bmpImage::bmpImage()
{
	
}

bmpImage::~bmpImage()
{

}

bool bmpImage::ImageRead_f_File(const char * filename)
{
	ifstream imageFile;

	try 
	{
		imageFile.open(filename);
		if(imageFile.fail())
			throw("bmpImage Error: ImageRead_f_File, file.open()");

		//-----------------------leitura dos parametros HEADER e INFOHEADER----------------------- 
			if(!this->header.HeaderRead_f_File(imageFile))	//le o HEADER atraves do metodo do metodo da composiçao "header"
				throw("bmpImage Error: ImageRead_f_File, header.HeaderRead_f_File(imageFile)");

			if (!this->infoheader.InfoHeaderRead_f_File(imageFile))	//le o HEADER atraves do metodo do metodo da composiçao "header"
				throw("bmpImage Error: ImageRead_f_File, infoheader.InfoHeaderRead_f_File(imageFile)");
		//-----------------------FIM leitura dos parametros HEADER e INFOHEADER----------------------- 


		//++++++++++++++++++++++++++ leitura do COLOR TABLE ++++++++++++++++++++++++++++++++++++++++++++++++++ 
			
			//	EM BRANCO POR AGORA

		//++++++++++++++++++++++++++ FIM leitura do COLOR TABLE ++++++++++++++++++++++++++++++++++++++++++++++++++


		//*************************** leitura do PIXELDATA ***************************************************



		//*************************** FIM leitura do PIXELDATA ***************************************************


	}catch (const char* str_err)
		{
			//insert error message	
			cout << str_err;
			return false;
		}
	






	return false;
}


/*
*LEITURA DO PIXELDATA DO FICHEIRO
*/
bool bmpImage::PixelDataRead_f_File(ifstream& file)
{
	uint32_t data_offset = this->infoheader.get_ImageSize();
	uint16_t n_bits_pixes = this->infoheader.get_bitsPpixel();



	try
	{
		if (file.fail())
			throw("bmpImage Error: PixelDataRead_f_File, file.fail()");

		if (!file.seekg(this->header.get_DataOffset()))	//poe o "index de leitura" do fichero a apontar para o inicio do PIXELDATA
			throw("bmpImage Error: PixelDataRead_f_File, unable to set the read index do beging of PIXELDATA");

		//---------------------loop de leitura dos pixels-----------------------------
			
		for (uint32_t i = 0; i < data_offset; i++)
		{

			switch (n_bits_pixes)
			{
				case 8:					   
					break;				   
				case 16:				   
					break;				   
				case 24:
						{	
						
						}
					break;
				case 32:
					break;

			default:
				break;
			}

		}
			
		//---------------------FIM loop de leitura dos pixels-----------------------------
	
	
	}
	catch (const char* str_err)
	{
		cout << str_err;
		return false;
	}

	
	return true;
}
