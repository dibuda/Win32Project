#pragma  once
#include "ggl.h"
#include "utils.h"
#include "skybox.h"
#include "model.h"
#include "Ground.h"
#include "light.h"
#include "Camera.h"
GLuint vbo;

SkyBox skybox;


Model model;
GLuint texture;
Ground ground;
DirectionLight dlight(GL_LIGHT0);
PointLight light1(GL_LIGHT1), light2(GL_LIGHT2);

Camera camera;
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
	model.mTexture= CreateTexture2DFromBMP("Res/earth.bmp");

	dlight.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	dlight.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
	dlight.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	dlight.SetPosition(0.0f, 1.0f, 0.0f);


	light1.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	light1.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
	light1.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	light1.SetPosition(0.0f, 0.0f, 0.0f);



	light2.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	light2.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
	light2.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	light2.SetPosition(0.0f, 0.0f, 0.0f);


	model.SetAmbienMaterial(0.1f, 0.1f, 0.1f, 1.0f);
	model.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
	model.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);

	ground.SetAmbienMaterial(0.1f, 0.1f, 0.1f, 1.0f);
	ground.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
	ground.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);

	

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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	dlight.Enable();
	camera.Update(GetFrameTime());
	skybox.DrawCommand(); 
	//glEnable(GL_DEPTH_TEST);

	model.Draw();
	ground.Draw();


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

void OnKeyDown(char code)
{
	switch (code)
	{
	case 'A':
		camera.mbMoveLeft = true;
		break;
	case 'D':
		camera.mbMoveRight = true;
		break;
	case 'W':
		camera.mbMoveForward = true;
		break;
	case 'S':
		camera.mbMoveBack = true;
		break;

	default:
		break;
	}

}
void OnKeyUp(char code)
{

	switch (code)
	{
	case 'A':
		camera.mbMoveLeft = false;
		break;
	case 'D':
		camera.mbMoveRight = false;
		break;
	case 'W':
		camera.mbMoveForward = false;
		break;
	case 'S':
		camera.mbMoveBack = false;
		break;

	default:
		break;
	}

}
void OnMouseMove(float deltaX, float deltaY)
{

}