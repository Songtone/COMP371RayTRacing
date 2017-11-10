#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "..\glm\glm.hpp"

using namespace std;

class Sphere {
	
public:
	
	/*Sphere(glm::vec3 p, float r, glm::vec3 a, glm::vec3 d, glm::vec3 s, float sh) {
		spherePos = p;
		rad = r;
		sphereAmb = a;
		sphereDif = d;
		sphereSpe = s;
		sphereShi = sh;S
	}*/
	glm::vec3 spherePos;
	float rad;
	glm::vec3 sphereAmb;
	glm::vec3 sphereDif;
	glm::vec3 sphereSpe;
	float sphereShi;

};
#endif // !SPHERE_H

