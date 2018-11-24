#pragma once
#include <windows.h>
#include "ggl.h"
class SkyBox
{

	GLuint mTextures[6];
	GLuint mFastDrawCall;
public:
	void Init(const char*imageDir);
	void DrawCommand();

};