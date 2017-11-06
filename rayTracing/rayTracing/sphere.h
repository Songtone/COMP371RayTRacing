#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>

using namespace std;

class Sphere {
	float posX, posY, posZ;
	float rad;
	float amb1, amb2, amb3;
	float dif1, dif2, dif3;
	float spe1, spe2, spe3;
	float shi;

	void setSpherePosX(float positionX) {
		posX = positionX;
	}
	float getSpherePosX() {
		return posX;
	}
	void setSpherePosY(float positionY) {
		posY = positionY;
	}
	float getSPherePosY() {
		return posY;
	}
	void setSpherePosZ(float positionZ) {
		posZ = positionZ;
	}
	float getSpherePosZ() {
		return posZ;
	}
	void setRadius(float radius) {
		rad = radius;
	}
	float getRadius() {
		return rad;
	}
	void setAmb1(float a1) {
		amb1 = a1;
	}
	float getAmb1() {
		return amb1;
	}
	void setAmb2(float a2) {
		amb2 = a2;
	}
	float getAmb2() {
		return amb2;
	}
	void setAmb3(float a3) {
		amb3 = a3;
	}
	float getAmb3() {
		return amb3;
	}
	void setDif1(float d1) {
		dif1 = d1;
	}
	float getDif1() {
		return dif1;
	}
	void setDif2(float d2) {
		dif2 = d2;
	}
	float getDif2() {
		return dif2;
	}
	void setDif3(float d3) {
		dif3 = d3;
	}
	float getDif3() {
		return dif3;
	}
	void setSpe1(float s1) {
		spe1 = s1;
	}
	float getSpe1() {
		return spe1;
	}
	void setSpe2(float s2) {
		spe2 = s2;
	}
	float getSpe2() {
		return spe2;
	}
	void setSpe3(float s3) {
		spe3 = s3;
	}
	float getSpe3() {
		return spe3;
	}
	void setShi(float sh) {
		shi = sh;
	}
	float getShi() {
		return shi;
	}
	Sphere() : posX(0), posY(0), posZ(0), rad(0), amb1(0), amb2(0), amb3(0), dif1(0), dif2(0), dif3(0), spe1(0), spe2(0), spe3(0), shi(0) {};
	Sphere(const Sphere& s) {
		posX = s.posX;
		posY = s.posY;
		posZ = s.posZ;
		rad = s.rad;
		amb1 = s.amb1;
		amb2 = s.amb2;
		amb3 = s.amb3;
		dif1 = s.dif1;
		dif2 = s.dif2;
		dif3 = s.dif3;
		spe1 = s.spe1;
		spe2 = s.spe2;
		spe3 = s.spe3;
		shi = s.shi;
	}
};
#endif // !SPHERE_H

