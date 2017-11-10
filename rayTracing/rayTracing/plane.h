#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include "..\glm\glm.hpp"


using namespace std;

class Plane {
public:

	glm::vec3 planeNorm;
	glm::vec3 planePos;
	glm::vec3 planeAmb;
	glm::vec3 planeDif;
	glm::vec3 planeSpe;
	


};


#endif
