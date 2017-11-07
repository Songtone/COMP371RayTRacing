#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "..\glm\glm.hpp"

class Light {
public:

	glm::vec3 lightPos;
	glm::vec3 lightColor;

	/*double posX, posY, posZ;
	double col1, col2, col3;*/


	//void setLightPosX(double positionX) {
	//	posX = positionX;
	//}
	//double getLightPosX() {
	//	return posX;
	//}
	//void setLightPosY(double positionY) {
	//	posY = positionY;
	//}
	//double getLightPosY() {
	//	return posY;
	//}
	//void setLightPosZ(double positionZ) {
	//	posZ = positionZ;
	//}
	//double getLightPosZ() {
	//	return posZ;
	//}
	//void setColor1(double color1) {
	//	col1 = color1;
	//}
	//double getColor1() {
	//	return col1;
	//}
	//void setColor2(double color2) {
	//	col2 = color2;
	//}
	//double getColor2() {
	//	return col2;
	//}
	//void setColor3(double color3) {
	//	col3 = color3;
	//}
	//double getColor3() {
	//	return col3;
	//}

	//Light() : posX(0), posY(0), posZ(0), col1(0), col2(0), col3(0) {}
	//Light(const Light& l) {
	//	posX = l.posX;
	//	posY = l.posY;
	//	posZ = l.posZ;
	//	col1 = l.col1;
	//	col2 = l.col2;
	//	col3 = l.col3;

	//}
};

#endif
