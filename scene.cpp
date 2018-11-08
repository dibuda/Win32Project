#pragma  once
#include "ggl.h"
GLuint vbo;

void Init()
{
	float data[] = {
		-0.2f,-0.2f,-0.6f,1.0f,
		 0.2f,-0.2f,-0.6f,1.0f,
		0.0f,-0.2f,-0.6f,1.0f
	};
	glGenBuffers(1, &vbo);

}
void SetViewportSize(float width, float height)
{

}
void Draw()
{

}