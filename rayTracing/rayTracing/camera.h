#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "..\glm\glm.hpp"


using namespace std;

class Camera {
public:

	glm::vec3 camPos;
	float fieldOfView;
	float focalLength;
	float aspectRatio;
	
	/*double posX, posY, posZ;
	double fieldOfView;
	double focalLength;
	double aspectRatio;
*/
	/*void setCamPosX(double positionX) {
		posX = positionX;
	}
	double getCamPosX() {
		return posX;
	}
	void setCamPosY(double positionY) {
		posY = positionY;
	}
	double getCamPosY() {
		return posY;
	}
	void setCamPosZ(double positionZ) {
		posZ = positionZ;
	}
	double getCamPosZ() {
		return posZ;
	}
	void setFieldOfView(double fov) {
		fieldOfView = fov;
	}
	double getFieldOfView() {
		return fieldOfView;
	}
	void setFocalLength(double f) {
		focalLength = f;
	}
	double getFocalLength() {
		return focalLength;
	}
	void setAspectRatio(double a) {
		aspectRatio = a;
	}
	double getAspectRatio() {
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
	}*/
};


#endif // !CAMERA_H

