#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "model.h"

using namespace std;

Camera camera;
Sphere sphere;
Light light;
Model model;

void createCameraPosition(string result);
void createCameraFOV(string result);
void createCameraFocalLength(string result);
void createCameraAspectRatio(string result);

void createSpherePosition(string result);
void createSphereRadius(string result);
void createSphereAmbiant(string result);
void createSphereDiffusion(string result);
void createSphereSpecular(string result);
void createSphereShininess(string result);

void createLightPosition(string result);
void createLightColor(string result);

void createModelName(string result);
void createModelAmbiance(string result);
void createModelDiffusion(string result);
void createModelSpecular(string result);
void createModelShininess(string result);

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
	camera.setAspectRatio(stod(storing[1]));

}
void createSphereRadius(string result) {

}
void createSphereAmbiant(string result) {

}
void createSphereDiffusion(string result) {

}
void createSphereSpecular(string result) {

}
void createSphereShininess(string result) {

}