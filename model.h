#pragma once
#include "ggl.h"

struct VertexData
{
	float position[3];
	float normal[3];
	float texcoord[2];

};

class Model
{
public:
	Model();
	void Init(const char *modelPath);
	void Draw();
	void SetAmbienMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);
	GLuint mTexture;
private:
	VertexData *mVertexes;
	unsigned short *mIndexes;
	int mIndexCount;
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];


};