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
	void Init(const char *modelPath);
	void Draw();

private:
	VertexData *mVertexes;
	unsigned short *mIndexes;
	int mIndexCount;

};