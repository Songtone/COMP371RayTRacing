#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>


using namespace std;

class Camera {
public:
	float posX, posY, posZ;
	float fieldOfView;
	float focalLength;
	float aspectRatio;

	void setCamPosX(float positionX) {
		posX = positionX;
	}
	float getCamPosX() {
		return posX;
	}
	void setCamPosY(float positionY) {
		posY = positionY;
	}
	float getCamPosY() {
		return posY;
	}
	void setCamPosZ(float positionZ) {
		posZ = positionZ;
	}
	float getCamPosZ() {
		return posZ;
	}
	void setFieldOfView(float fov) {
		fieldOfView = fov;
	}
	float getFieldOfView() {
		return fieldOfView;
	}
	void setFocalLength(float f) {
		focalLength = f;
	}
	float getFocalLength() {
		return focalLength;
	}
	void setAspectRatio(float a) {
		aspectRatio = a;
	}
	float getAspectRatio() {
		return aspectRatio;
	}

	Camera() : posX(0), posY(0), posZ(0), fieldOfView(0), focalLength(0), aspectRatio(0) {};

	Camera(const Camera& c) {
		posX = c.posX;
		posY = c.posY;
		posZ = c.posZ;
		fieldOfView = c.fieldOfView;
		focalLength = c.focalLength;
		aspectRatio = c.aspectRatio;
	}
};


#endif // !CAMERA_H

