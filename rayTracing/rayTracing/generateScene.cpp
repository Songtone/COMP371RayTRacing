#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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