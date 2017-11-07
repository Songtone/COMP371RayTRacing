#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "..\glm\glm.hpp"


using namespace std;

class Triangle {
public:

	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 v3;
	glm::vec3 triAmb;
	glm::vec3 triDif;
	glm::vec3 triSpe;
	float triShi;
};
#endif