#include "skybox.h"
#include "utils.h"

void SkyBox::Init(const char*imageDir)
{ 
	char temp[256] = { 0 };
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/front.bmp");
	mTextures[0] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/back.bmp");
	mTextures[1] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/top.bmp");
	mTextures[2] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/bottom.bmp");
	mTextures[3] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/left.bmp");
	mTextures[4] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	strcpy(temp, imageDir);
	strcat(temp, "/right.bmp");
	mTextures[5] = CreateTexture2DFromBMP(temp);
	memset(temp, 0, 256);
	//mFastDrawCall = CreateDisplayList([this]()->void {DrawCommand();});
}

void SkyBox::DrawCommand()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	//front

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTextures[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	//left
	glBindTexture(GL_TEXTURE_2D, mTextures[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, mTextures[2]);
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, mTextures[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//bottom
	glBindTexture(GL_TEXTURE_2D, mTextures[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, mTextures[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glEnd();

	//glPopMatrix();
}