#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "generateScene.h"
#include "CImg.h"
#include "../glm/glm.hpp"
//used this website to learn about ray tracing https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays

using namespace std;
using namespace cimg_library;

//variables
glm::vec3 rayDirection;
float pi = 3.1415965;
int height;
int width;
float camPixelX;
float camPixelY;


int main() {
	readTextFile("..\\scene_files\\sceneOBJ.txt");
	displayObjectsAttributes();

	height = 2 * (camera.focalLength*glm::tan(glm::radians(camera.fieldOfView) / 2));
	width = camera.aspectRatio*height;
	CImg<float> picture(width, height, 1, 3, 0);
		
		//starting rayTracing
	for (int i = 0; i < height; i++) {//for the height of the image, we will go through every pixel in that width. then go to the next height
		for (int j = 0; j < width; j++) {

			camPixelX = (2 * ((j + 0.5) / width) - 1)*tan(camera.fieldOfView / 2 * pi / 180)*camera.aspectRatio;
			camPixelY = (1 - 2 * ((i + 0.5) / height))*tan(camera.fieldOfView / 2 * pi / 180);

			rayDirection = glm::vec3(camPixelX, camPixelY, -1) - camera.camPos;
			rayDirection = glm::normalize(rayDirection);
			glm::vec3 colorPixel(0.0f);
			
			float tempDist;
			float distance;
			glm::vec3 tempIntersect;
			glm::vec3 intersect;
			

				if (sphereIntersection(sphere.spherePos, camera.camPos, rayDirection, sphere.rad, tempIntersect, tempDist)) {
					colorPixel = sphere.sphereAmb;
				
				float color[3]{ colorPixel.x,colorPixel.y,colorPixel.z };
				picture.draw_point(j, i, color);
			}
		}
	}
	

	//display the scene window
	CImgDisplay sceneDisp(picture, "Current Scene");
	picture.normalize(0, 255);
	
	picture.save("dandaman.bmp");

	system("pause");
}

void readTextFile(string fileName) {//reading and storing all the attribute information for each individual objects.
	ifstream readFile(fileName);
	string line;

	while (getline(readFile, line)) {
		if (line == "camera") {

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

			//Sphere newSphere(tempSpherePos,tempSphereRad,tempSphereAmb,tempSphereDif,tempSphereSpe,tempSphereShi);
			//spheres.emplace_back(newSphere);


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
		else if (line == "triangle") {
			getline(readFile, line);
			createTriangleV1(line);
			getline(readFile, line);
			createTriangleV2(line);
			getline(readFile, line);
			createTriangleV3(line);
			getline(readFile, line);
			createTriangleAmbiance(line);
			getline(readFile, line);
			createTriangleDiffusion(line);
			getline(readFile, line);
			createTriangleSpecular(line);
			getline(readFile, line);
			createTriangleShininess(line);

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
	//glm::vec3 tempSpherePos = glm::vec3(a, b, c);
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
	//glm::vec3 tempSphereAmb = glm::vec3(a, b, c);
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
	//glm::vec3 tempSphereDif = glm::vec3(a, b, c);
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
	//glm::vec3 tempSphereSpe = glm::vec3(a, b, c);
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
	//float tempSphereShi = (stof(result));
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
void createTriangleV1(string result) {

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
triangle.triV1 = glm::vec3(a, b, c);
}
void createTriangleV2(string result) {
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
	triangle.triV2 = glm::vec3(a, b, c);
}
void createTriangleV3(string result) {
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
	triangle.triV3 = glm::vec3(a, b, c);
}
void createTriangleAmbiance(string result) {
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
	triangle.triAmb = glm::vec3(a, b, c);
}
void createTriangleDiffusion(string result) {
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
	triangle.triDif = glm::vec3(a, b, c);
}
void createTriangleSpecular(string result) {
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
	triangle.triSpe = glm::vec3(a, b, c);
}
void createTriangleShininess(string result) {
	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	triangle.triShi = (stof(result));
}
//reference https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
bool sphereIntersection(glm::vec3 spherePos, glm::vec3 camPos, glm::vec3 rayDir, float radians, glm::vec3& intersection,float& d) {
	float rad2 = radians * radians;
	float r0, r1;
	glm::vec3 L = spherePos - camPos;
	float rca = glm::dot(L, rayDir);

	float d2 = glm::dot(L, L) - rca * rca;
	if (d2 > rad2)
	{
	return false;
	}
	float thc = sqrt((rad2 - d2));
	r0 = rca - thc;
	r1 = rca + thc;

	if (r0 > r1) swap(r0, r1);

	if (r0 < 0) {
		r0 = r1;
		if (r0 < 0) {
			return false;
		}
	}
	d = r0;
	intersection = camPos + rayDir * d;
	return true;

}
//reference for triangle https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution

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
	cout << endl;
	cout << "Triangle" << endl;
	cout << "V1 coord: " << triangle.triV1.x << " " << triangle.triV1.y << " " << triangle.triV1.z << endl;
	cout << "V2 coord: " << triangle.triV2.x << " " << triangle.triV2.y << " " << triangle.triV2.z << endl;
	cout << "V3 coord: " << triangle.triV3.x << " " << triangle.triV3.y << " " << triangle.triV3.z << endl;
	cout << "Ambiance: " << triangle.triAmb.x << " " << triangle.triAmb.y << " " << triangle.triAmb.z << endl;
	cout << "Diffusion: " << triangle.triDif.x << " " << triangle.triDif.y << " " << triangle.triDif.z << endl;
	cout << "Specular: " << triangle.triSpe.x << " " << triangle.triSpe.y << " " << triangle.triSpe.z << endl;
	cout << "Shininess: " << triangle.triShi << endl;

}