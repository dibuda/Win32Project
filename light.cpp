
#include "light.h"
Light::Light()
{
}

Light::~Light()
{
}

void Light::SetAmbientColor(float r, float g, float b, float a)
{
	float ambientColor[] = { r,g,b,a };
	glLightfv(mLightIdentifier, GL_AMBIENT, ambientColor);

}
void Light::SetDiffuseColor(float r, float g, float b, float a)
{
	float diffuseColor[] = { r,g,b,a };
	glLightfv(mLightIdentifier, GL_DIFFUSE, diffuseColor);

}
void Light::SetSpecularColor(float r, float g, float b, float a)
{
	float specularColor[] = { r,g,b,a };
	glLightfv(mLightIdentifier, GL_SPECULAR, specularColor);
}

void Light::Enable()
{

	glEnable(GL_LIGHTING);
	glEnable(mLightIdentifier);

}


DirectionLight::DirectionLight(GLuint light)
{
	mLightIdentifier = light;
}

void DirectionLight::SetPosition(float x, float y, float z)
{
	float pos[] = { x,y,z,0.0f };
	glLightfv(mLightIdentifier, GL_POSITION, pos);
}

PointLight::PointLight(GLuint light)
{
	mLightIdentifier = light;
}
void PointLight::SetPosition(float x, float y, float z)
{
	float pos[] = { x,y,z,1.0f };
	glLightfv(mLightIdentifier, GL_POSITION, pos);

}
void PointLight::SetConstAttenuation(float v)
{
	glLightf(mLightIdentifier, GL_CONSTANT_ATTENUATION, v);
}
void PointLight::SetLinearAttenuation(float v)
{
	glLightf(mLightIdentifier, GL_LINEAR_ATTENUATION, v);
}
void PointLight::SetQuadricAttenuation(float v)
{
	glLightf(mLightIdentifier, GL_QUADRATIC_ATTENUATION, v);
}
