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
	
	
};


#endif // !CAMERA_H

