#pragma once
#include "ggl.h";
class Light
{
public:
	Light();
	~Light();
public:
	void SetAmbientColor(float r, float g, float b, float a);
	void SetDiffuseColor(float r, float g, float b, float a);
	void SetSpecularColor(float r, float g, float b, float a);
	void Enable();

	GLuint mLightIdentifier;

};
class DirectionLight:public Light
{
public:
	DirectionLight(GLuint light);
	void SetPosition(float x, float y, float z);


private:

};

class PointLight :public Light
{
public:
	PointLight(GLuint light);
	void SetPosition(float x, float y, float z);
	void SetConstAttenuation(float v);
	void SetLinearAttenuation(float v);
	void SetQuadricAttenuation(float v);



private:

};