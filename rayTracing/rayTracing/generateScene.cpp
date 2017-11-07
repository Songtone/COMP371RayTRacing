#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "generateScene.h"
#include "CImg.h"
#include "../glm/glm.hpp"

using namespace std;


int maint() {

}

void readTextFile(string fileName) {
	ifstream readFile(fileName);
	string line;

	while (getline(readFile, line)) {
		if (line == "camera") {//getting settings for the camera

			getline(readFile, line);
			createCameraPosition(line);
			getline(readFile, line);
			createCameraFOV(line);
			getline(readFile, line);
			createCameraFocalLength(line);
			getline(readFile, line);
			createCameraAspectRatio(line);

		}
		else if (line == "sphere") {

			getline(readFile, line);
			createSpherePosition(line);
			getline(readFile, line);
			createSphereRadius(line);
			getline(readFile, line);
			createSphereAmbiant(line);
			getline(readFile, line);
			createSphereDiffusion(line);
			getline(readFile, line);
			createSphereSpecular(line);
			getline(readFile, line);
			createSphereShininess(line);

		}
		else if (line == "light") {

			getline(readFile, line);
			createLightColor(line);
			getline(readFile, line);
			createLightColor(line);

		}
		else if (line == "model") {

			getline(readFile, line);
			createModelName(line);
			getline(readFile, line);
			createModelAmbiance(line);
			getline(readFile, line);
			createModelDiffusion(line);
			getline(readFile, line);
			createModelSpecular(line);
			getline(readFile, line);
			createModelShininess(line);

		}
	}
	readFile.close();
}
//string splitting(string s, string delimiter) {
//	int counter = 0;
//	size_t pos = 0;
//	string *storing;
//	storing = new string[];
//	while ((pos = s.find(delimiter)) != string::npos) {
//		storing[counter] = s.substr(0, pos);
//		s.erase(0, pos + delimiter.length());
//		counter++;
//	}
//
//	
//
//}

//Camera functions
void createCameraPosition(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}

	camera.setCamPosX(stod(storing[1]));
	camera.setCamPosY(stod(storing[2]));
	camera.setCamPosZ(stod(storing[3]));
}
void createCameraFOV(string result){

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.setFieldOfView(stod(storing[1]));

}
void createCameraFocalLength(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.setFocalLength(stod(storing[1]));

}
void createCameraAspectRatio(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.setAspectRatio(stod(storing[1]));

}
//Sphere Functions
void createSpherePosition(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setSpherePosX(stod(storing[1]));
	sphere.setSpherePosY(stod(storing[2]));
	sphere.setSpherePosZ(stod(storing[3]));

}
void createSphereRadius(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setRadius(stod(storing[1]));
}
void createSphereAmbiant(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setAmb1(stod(storing[1]));
	sphere.setAmb2(stod(storing[2]));
	sphere.setAmb3(stod(storing[3]));

}
void createSphereDiffusion(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setDif1(stod(storing[1]));
	sphere.setDif2(stod(storing[2]));
	sphere.setDif3(stod(storing[3]));

}
void createSphereSpecular(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setSpe1(stod(storing[1]));
	sphere.setSpe2(stod(storing[2]));
	sphere.setSpe3(stod(storing[3]));

}
void createSphereShininess(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.setShi(stod(storing[1]));
	
}
//Light Functions
void createLightPosition(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	light.setLightPosX(stod(storing[1]));
	light.setLightPosY(stod(storing[2]));
	light.setLightPosZ(stod(storing[3]));

}
void createLightColor(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	light.setColor1(stod(storing[1]));
	light.setColor2(stod(storing[2]));
	light.setColor3(stod(storing[3]));
}
//Model Functions
void createModelName(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.setModelName(storing[0]);
}
void createModelAmbiance(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.setAmb1(stod(storing[1]));
	model.setAmb2(stod(storing[2]));
	model.setAmb3(stod(storing[3]));

}
void createModelDiffusion(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.setDif1(stod(storing[1]));
	model.setDif2(stod(storing[2]));
	model.setDif3(stod(storing[3]));
}
void createModelSpecular(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.setSpe1(stod(storing[1]));
	model.setSpe2(stod(storing[2]));
	model.setSpe3(stod(storing[3]));

}
void createModelShininess(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string *storing;
	storing = new string[];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.setShi(stod(storing[1]));
	
}