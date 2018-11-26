#include "Camera.h"
#include "utils.h"


Camera::Camera():mPos(0.0f,0.0f,0.0f),mViewCenter(0.0f,0.0f,-1.0f),mUp(0.0f,1.0f,0.0f)
{
	mbMoveLeft = false;
	mbMoveRight = false;
	mbMoveForward = false;
	mbMoveBack = false;
}

void Camera::Update(float deltaTime)
{
	float moveSpeed = 1.0f;
	Vector3f forwardDirection = mViewCenter - mPos;
	forwardDirection.Normalize();
	Vector3f rightDirection = Cross(forwardDirection, mUp);
	rightDirection.Normalize();

	if (mbMoveLeft)
	{
		Vector3f delta = rightDirection*deltaTime*moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;

	}

	if (mbMoveRight)
	{
		Vector3f delta = rightDirection*deltaTime*moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;

	}

	if (mbMoveForward)
	{
		Vector3f delta = forwardDirection*deltaTime*moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;

	}
	if (mbMoveBack)
	{
		Vector3f delta = forwardDirection*deltaTime*moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;

	}
	glLoadIdentity();
	gluLookAt(mPos.x, mPos.y, mPos.z, mViewCenter.x, mViewCenter.y, mViewCenter.z, mUp.x, mUp.y, mUp.z);
}