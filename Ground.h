#pragma once
class Ground
{
public:
	void Draw();
	void SetAmbienMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);

private:
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];


};
