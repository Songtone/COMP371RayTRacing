#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "model.h"
#include "generateScene.h"
#include "CImg.h"
#include "../glm/glm.hpp"

using namespace std;


//int main() {
//	readTextFile("sceneObject.txt");
//	
//
//}

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
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		cout << storing[counter] << endl;
		counter++;
	}
	double a = stod(storing[1]);
	double b = stod(storing[2]);
	double c = stod(result);
	camera.posX = a;
	camera.posY = b;
	camera.posZ = c;
}
void createCameraFOV(string result){

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[2];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.fieldOfView = (stod(storing[1]));

}
void createCameraFocalLength(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.fieldOfView = (stod(storing[1]));

}
void createCameraAspectRatio(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	camera.aspectRatio = (stod(storing[1]));

}
//Sphere Functions
void createSpherePosition(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.posX = (stod(storing[1]));
	sphere.posY = (stod(storing[2]));
	sphere.posZ = (stod(storing[3]));

}
void createSphereRadius(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.rad = (stod(storing[1]));
}
void createSphereAmbiant(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.amb1 = (stod(storing[1]));
	sphere.amb2 = (stod(storing[2]));
	sphere.amb3 = (stod(storing[3]));

}
void createSphereDiffusion(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.dif1 = (stod(storing[1]));
	sphere.dif2 = (stod(storing[2]));
	sphere.dif3 = (stod(storing[3]));

}
void createSphereSpecular(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.spe1 = (stod(storing[1]));
	sphere.spe2 = (stod(storing[2]));
	sphere.spe3 =(stod(storing[3]));

}
void createSphereShininess(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	sphere.shi = (stod(storing[1]));
	
}
//Light Functions
void createLightPosition(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	light.posX = (stod(storing[1]));
	light.posY = (stod(storing[2]));
	light.posZ = (stod(storing[3]));

}
void createLightColor(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	light.col1 = (stod(storing[1]));
	light.col2 = (stod(storing[2]));
	light.col3 = (stod(storing[3]));
}
//Model Functions
void createModelName(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.modelFile = (storing[0]);
}
void createModelAmbiance(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.amb1 = (stod(storing[1]));
	model.amb2 = (stod(storing[2]));
	model.amb3 = (stod(storing[3]));

}
void createModelDiffusion(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.dif1 = (stod(storing[1]));
	model.dif2 = (stod(storing[2]));
	model.dif3 = (stod(storing[3]));
}
void createModelSpecular(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.spe1 = (stod(storing[1]));
	model.spe2 = (stod(storing[2]));
	model.spe3 = (stod(storing[3]));

}
void createModelShininess(string result) {

	string delimiter = " ";
	int counter = 0;
	size_t pos = 0;
	string storing[4];
	while ((pos = result.find(delimiter)) != string::npos) {
		storing[counter] = result.substr(0, pos);
		result.erase(0, pos + delimiter.length());
		counter++;
	}
	model.shi = (stod(storing[1]));
	
}