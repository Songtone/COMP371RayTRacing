#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

class Light {
	float posX, posY, posZ;
	float col1, col2, col3, col4;


	void setLightPosX(float positionX) {
		posX = positionX;
	}
	float getLightPosX() {
		return posX;
	}
	void setLightPosY(float positionY) {
		posY = positionY;
	}
	float getLightPosY() {
		return posY;
	}
	void setLightPosZ(float positionZ) {
		posZ = positionZ;
	}
	float getLightPosZ() {
		return posZ;
	}
	void setColor1(float color1) {
		col1 = color1;
	}
	float getColor1() {
		return col1;
	}
	void setColor2(float color2) {
		col2 = color2;
	}
	float getColor2() {
		return col2;
	}
	void setColor3(float color3) {
		col3 = color3;
	}
	float getColor3() {
		return col3;
	}

	Light() : posX(0), posY(0), posZ(0), col1(0), col2(0), col3(0) {}
	Light(const Light& l) {
		posX = l.posX;
		posY = l.posY;
		posZ = l.posZ;
		col1 = l.col1;
		col2 = l.col2;
		col3 = l.col3;

	}
};

#endif
