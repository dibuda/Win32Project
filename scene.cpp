#pragma  once
#include "ggl.h"
#include "utils.h"
#include "skybox.h"
#include "model.h"
GLuint vbo;

SkyBox skybox;


Model model;
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
	model.Init("Res/Sphere.obj");

	//texture = CreateTexture2DFromBMP("Res/test.bmp");




}
void SetViewportSize(float width, float height)
{

}

void DrawModel()
{
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	//glVertex3f(-0.5f, -0.2f, -0.5f);;
	//glVertex3f(0.5f, -0.2f, -0.5f);
	//glVertex3f(0.5f, -0.2f, -1.5f);
	//glVertex3f(-0.5f, -0.2f, -1.5f);



	glEnd();
}
void Draw()
{
	glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	skybox.DrawCommand(); 
	//glEnable(GL_DEPTH_TEST);

	model.Draw();

	//glBegin(GL_QUADS);
	//glColor4ub(255, 255, 255, 255);
	//glVertex3f(-0.1f, -0.1f, -0.6f);;
	//glVertex3f(0.1f, -0.1f, -0.6f);
	//glVertex3f(0.1f, 0.1f, -0.6f);
	//glVertex3f(-0.1f, 0.1f, -0.6f);

	//glVertex3f(-0.1f, -0.1f, -0.4f);;
	//glVertex3f(0.1f, -0.1f, -0.4f);
	//glVertex3f(0.1f, 0.1f, -0.4f);
	//glVertex3f(-0.1f, 0.1f, -0.4f);

	//glEnd();








}