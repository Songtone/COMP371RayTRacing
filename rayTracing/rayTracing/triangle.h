#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "..\glm\glm.hpp"


using namespace std;

class Triangle {
public:
	Triangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 a, glm::vec3 d, glm::vec3 spe, float shi) {
		triV1 = v1;
		triV2 = v2;
		triV3 = v3;
		triAmb = a;
		triDif = d;
		triSpe = spe;
		triShi = shi;
	}
	glm::vec3 triV1;
	glm::vec3 triV2;
	glm::vec3 triV3;
	glm::vec3 triAmb;
	glm::vec3 triDif;
	glm::vec3 triSpe;
	float triShi;
};
#endif