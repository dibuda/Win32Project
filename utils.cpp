#include "utils.h"
unsigned char * DecodeBMP(unsigned char *bmpFileDate, int &width, int&height)
{
	if (0x4D42==*((unsigned short*)bmpFileDate))
	{
		int pixelDataOffset = *((int *)(bmpFileDate + 10));
		width= *((int *)(bmpFileDate + 18));
		height = *((int *)(bmpFileDate + 22));

		unsigned char *pixelData = bmpFileDate + pixelDataOffset;
		for (int i=0;i<width*height*3;i+=3)
		{
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i + 2];
			pixelData[i+2] = temp;

		}
		return pixelData;
	}
	return nullptr;

}

GLuint CreateTexture2D(unsigned char *pixelData, int width, int height, GLenum type)
{
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixelData);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}

GLuint CreateTexture2DFromBMP(const char *bmpPath)
{

	int nfileSize = 0;
	unsigned char *bmpFileContent = LoadFileContent(bmpPath, nfileSize);
	if (bmpFileContent == nullptr)
		return 0;
	int bmpWidth = 0; int bmpHeight = 0;
	unsigned char *pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
	if (bmpWidth == 0)
	{
		delete bmpFileContent;
		return 0;
	}
		
	GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
	delete bmpFileContent;
	return texture;
}