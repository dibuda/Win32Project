#pragma  once
#include "ggl.h"
#include "utils.h"
#include "skybox.h"
GLuint vbo;

SkyBox skybox;

GLuint texture;
void Init()
{
	//float data[] = {
	//	-0.2f,-0.2f,-0.6f,1.0f,
	//	 0.2f,-0.2f,-0.6f,1.0f,
	//	0.0f,-0.2f,-0.6f,1.0f
	//};
	//glGenBuffers(1, &vbo);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f, 800.0f / 600.00f, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	skybox.Init("Res/skybox/");


	//texture = CreateTexture2DFromBMP("Res/test.bmp");




}
void SetViewportSize(float width, float height)
{

}
void Draw()
{
	//glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//-------------------------------------------------------------------------------------------------------------

	//glBegin(GL_TRIANGLES);
	//glColor4ub(255, 0, 0, 255);glVertex3f(-2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 255, 0, 255);glVertex3f(2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 0, 255, 255);glVertex3f(0.0f,2.0f, -10.0f);
	//glColor4ub(255, 255, 0, 255);glVertex3f(4.0f, 2.0f, -10.0f);
	//glColor4ub(0, 255, 255, 255);glVertex3f(2.0f, 6.0f, -10.0f);
	//glColor4ub(255, 255, 255, 255);glVertex3f(6.0f, 6.0f, -10.0f);
	//glEnd();

	//glBegin(GL_TRIANGLE_STRIP);
	//glColor4ub(255, 0, 0, 255);glVertex3f(-2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 255, 0, 255);glVertex3f(2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 0, 255, 255);glVertex3f(0.0f, 2.0f, -10.0f);
	//glColor4ub(255, 255, 0, 255);glVertex3f(4.0f, 2.0f, -10.0f);
	//glColor4ub(0, 255, 255, 255);glVertex3f(2.0f, 6.0f, -10.0f);
	//glColor4ub(255, 255, 255, 255);glVertex3f(6.0f, 6.0f, -10.0f);
	//glEnd();

	//glBegin(GL_TRIANGLE_STRIP);
	//glColor4ub(255, 0, 0, 255);glVertex3f(-2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 255, 0, 255);glVertex3f(2.0f, -2.0f, -10.0f);
	//glColor4ub(0, 0, 255, 255);glVertex3f(0.0f, 2.0f, -10.0f);
	//glColor4ub(255, 255, 0, 255);glVertex3f(4.0f, 2.0f, -10.0f);
	//glColor4ub(0, 255, 255, 255);glVertex3f(2.0f, 6.0f, -10.0f);
	//glColor4ub(255, 255, 255, 255);glVertex3f(6.0f, 6.0f, -10.0f);
	//glEnd();


	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture);

	//glBegin(GL_QUADS);
	//glColor4ub(255, 255, 255, 255);
	////glColor4ub(0, 0, 0, 255);
	//glTexCoord2f(0.0f, 0.0f);glVertex3f(-2.0f, -2.0f, -10.0f);
	//glTexCoord2f(1.0f, 0.0f);glVertex3f(2.0f, -2.0f, -10.0f);
	//glTexCoord2f(1.0f, 1.0f);glVertex3f(2.0f, 2.0f, -10.0f);
	//glTexCoord2f(0.0f, 1.0f);glVertex3f(-2.0f, 2.0f, -10.0f);
	//glEnd();


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// 	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER);
// 	glEnable(GL_DEPTH_TEST);
	skybox.Draw();
	glBegin(GL_QUADS);
	glColor4ub(200, 50, 0, 255);
	glVertex3f(-0.1f, -0.1f, -0.4f);
	glVertex3f(0.1f, -0.1f, -0.4f);
	glVertex3f(0.1f, 0.1f, -0.4f);
	glVertex3f(-0.1f, 0.1f, -0.4f);

	//glColor4ub(0, 50, 200, 255);
	//glVertex3f(-0.1f, -0.1f, -0.6f);
	//glVertex3f(0.1f, -0.1f, -0.6f);
	//glVertex3f(0.1f, 0.1f, -0.6f);
	//glVertex3f(-0.1f, 0.1f, -0.6f);

	glEnd();





}