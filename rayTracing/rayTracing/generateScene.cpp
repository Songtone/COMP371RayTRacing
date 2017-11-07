#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "generateScene.h"
#include "CImg.h"
#include "../glm/glm.hpp"

using namespace std;



int main() {
	readTextFile("sceneObject.txt");
	displayObjectsAttributes();


	system("pause");
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
	
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());
	
	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	camera.camPos = glm::vec3(a, b, c);
	
}
void createCameraFOV(string result){

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	camera.fieldOfView = (stof(result));

}
void createCameraFocalLength(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	camera.focalLength = (stof(result));

}
void createCameraAspectRatio(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	camera.aspectRatio = (stof(result));

}
//Sphere Functions
void createSpherePosition(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	sphere.spherePos = glm::vec3(a, b, c);

}
void createSphereRadius(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	sphere.rad = (stof(result));
}
void createSphereAmbiant(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	sphere.sphereAmb = glm::vec3(a, b, c);

}
void createSphereDiffusion(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	sphere.sphereDif = glm::vec3(a, b, c);

}
void createSphereSpecular(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	sphere.sphereSpe = glm::vec3(a, b, c);

}
void createSphereShininess(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	sphere.sphereShi = (stof(result));
	
}
//Light Functions
void createLightPosition(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	light.lightPos = glm::vec3(a, b, c);

}
void createLightColor(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	light.lightColor = glm::vec3(a, b, c);
}
//Model Functions
void createModelName(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	model.modelFile = (result);
}
void createModelAmbiance(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	model.modelAmb = glm::vec3(a, b, c);

}
void createModelDiffusion(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	model.modelDif = glm::vec3(a, b, c);
}
void createModelSpecular(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	float a = stof(storing[1]);
	float b = stof(storing[2]);
	float c = stof(result);
	model.modelSpe = glm::vec3(a, b, c);

}
void createModelShininess(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	model.modelShi = (stof(result));
	
}
void displayObjectsAttributes() {

	cout << "Camera" << endl;
	cout << "Position: "<< camera.camPos.x <<" "<< camera.camPos.y << " "<< camera.camPos.z << endl;
	cout << "Field Of View: " << camera.fieldOfView << endl;
	cout << "Focal Length: " << camera.focalLength << endl;
	cout << "Aspect Ratio: " << camera.aspectRatio << endl;
	cout << endl;
	cout << "Sphere" << endl;
	cout << "Position: "<< sphere.spherePos.x << " " << sphere.spherePos.y << " " << sphere.spherePos.z << endl;
	cout << "Radius: " << sphere.rad << endl;
	cout << "Ambiance: " << sphere.sphereAmb.x << " " << sphere.sphereAmb.y << " " << sphere.sphereAmb.z << endl;
	cout << "Diffusion" << sphere.sphereDif.x << " " << sphere.sphereDif.y << " " << sphere.sphereDif.z << endl;
	cout << "Specular: " << sphere.sphereSpe.x << " " << sphere.sphereSpe.y << " " << sphere.sphereSpe.z << endl;
	cout << "Shininess: " << sphere.sphereShi << endl;
	cout << endl;
	cout << "Light" << endl;
	cout << "Position: "<< light.lightPos.x << " " << light.lightPos.y << " " << light.lightPos.z << endl;
	cout << "Color: " << light.lightColor.x << " " << light.lightColor.y << " " << light.lightColor.z << endl;
	cout << endl;
	cout << "Model" << endl;
	cout << "Model Name: " << model.modelFile << endl;
	cout << "Ambiance: " << model.modelAmb.x << " " << model.modelAmb.y << " " << model.modelAmb.z << endl;
	cout << "Diffusion: " << model.modelDif.x << " " << model.modelDif.y << " " << model.modelDif.z << endl;
	cout << "Specular: " << model.modelSpe.x << " " << model.modelSpe.y << " " << model.modelSpe.z << endl;
	cout << "Shininess: " << model.modelShi << endl;

}