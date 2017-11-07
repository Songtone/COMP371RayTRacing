#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include "..\glm\glm.hpp"

using namespace std;

class Model {
public:
	string modelFile;
	glm::vec3 modelAmb;
	glm::vec3 modelDif;
	glm::vec3 modelSpe;
	float modelShi;

	/*double amb1, amb2, amb3;
	double dif1, dif2, dif3;
	double spe1, spe2, spe3;
	double shi;
*/
	/*void setModelName(string name) {
		modelFile = name;
	}

	void setAmb1(double a1) {
		amb1 = a1;
	}
	double getAmb1() {
		return amb1;
	}
	void setAmb2(double a2) {
		amb2 = a2;
	}
	double getAmb2() {
		return amb2;
	}
	void setAmb3(double a3) {
		amb3 = a3;
	}
	double getAmb3() {
		return amb3;
	}
	void setDif1(double d1) {
		dif1 = d1;
	}
	double getDif1() {
		return dif1;
	}
	void setDif2(double d2) {
		dif2 = d2;
	}
	double getDif2() {
		return dif2;
	}
	void setDif3(double d3) {
		dif3 = d3;
	}
	double getDif3() {
		return dif3;
	}
	void setSpe1(double s1) {
		spe1 = s1;
	}
	double getSpe1() {
		return spe1;
	}
	void setSpe2(double s2) {
		spe2 = s2;
	}
	double getSpe2() {
		return spe2;
	}
	void setSpe3(double s3) {
		spe3 = s3;
	}
	double getSpe3() {
		return spe3;
	}
	void setShi(double sh) {
		shi = sh;
	}
	double getShi() {
		return shi;
	}
	Model() : modelFile("default"),amb1(0), amb2(0), amb3(0), dif1(0), dif2(0), dif3(0), spe1(0), spe2(0), spe3(0), shi(0) {};
	Model(const Model& m) {
		modelFile = m.modelFile;
		amb1 = m.amb1;
		amb2 = m.amb2;
		amb3 = m.amb3;
		dif1 = m.dif1;
		dif2 = m.dif2;
		dif3 = m.dif3;
		spe1 = m.spe1;
		spe2 = m.spe2;
		spe3 = m.spe3;
		shi = m.shi;
	}*/
};


#endif // !MODEL_H

