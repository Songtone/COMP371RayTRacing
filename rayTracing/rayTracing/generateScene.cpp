#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "generateScene.h"
#include "CImg.h"
#include "../glm/glm.hpp"
//used this website to learn about ray tracing https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
//got help from Daniel Privorotsky
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
	readTextFile("..\\scene_files\\scene4.txt");
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


			float closestDistance;
			glm::vec3 intersect;
			int closestPixel;
			int empty = 0;
			int colorThePixel = 0;
			for (int k = 0; k < spheres.size(); k++) {//sphere intersect section
				float sphereTempDist;
				glm::vec3 sphereTempIntersect;
				if (sphereIntersection(spheres[k].spherePos, camera.camPos, rayDirection, spheres[k].rad, sphereTempIntersect, sphereTempDist)) {
					if (!empty || sphereTempDist < closestDistance) {
						closestDistance = sphereTempDist;
						intersect = sphereTempIntersect;
						closestPixel = k;
						empty = 1;
						colorThePixel = 1;
					}


				}
				/*if (colorThePixel == 1) {
					colorPixel = spheres[closestPixel].sphereAmb;
				}*/
			}
			for (int l = 0; l < triangles.size(); l++) {//triangle intersect section
				float triangleTempDist;
				glm::vec3 triangleTempIntersect;
				if (triangleIntersection(camera.camPos, rayDirection, triangles[l], triangleTempIntersect, triangleTempDist)) {
					if (!empty || triangleTempDist < closestDistance) {
						closestDistance = triangleTempDist;
						intersect = triangleTempIntersect;
						closestPixel = l;
						empty = 1;
						colorThePixel = 2;

					}
					/*if (colorThePixel == 2) {
						colorPixel = triangles[closestPixel].triAmb;
					}*/
				}
			}
			float planeTempDist;
			glm::vec3 planeTempIntersect;
			if (planeIntersection(plane.planeNorm,plane.planePos,camera.camPos,rayDirection,planeTempIntersect,planeTempDist)) {
				if (!empty || planeTempDist < closestDistance) {
					closestDistance = planeTempDist;
					intersect = planeTempIntersect;
					empty = 1;
					colorThePixel = 3;

				}
				if (colorThePixel == 3) {
					colorPixel = plane.planeAmb;
				}
			}

			bool shadow = true;
			float shadowOffset = 1e-3;

			for (int m = 0; m < lights.size(); m++) {//each light gets to check if anything is in the way to project light/ shadow
				if (colorThePixel != 0) {
					//get light ray direction
					glm::vec3 lightRayDirection = glm::normalize(lights[m].lightPos - intersect);

					//see if the light goes through this sphere object
					for (int k = 0; k < spheres.size(); k++) {
						float tempSphereDist;
						glm::vec3 tempSphereIntersect;
						if (sphereIntersection(spheres[k].spherePos, intersect + (shadowOffset * lightRayDirection), lightRayDirection, spheres[k].rad, tempSphereIntersect, tempSphereDist)) {
							shadow = false;
						}

					}
					//see if the light goes through this triangle object
					for (int k = 0; k < triangles.size(); k++) {
						float tempTriangleDist;
						glm::vec3 tempTriangleIntersect;
						if (triangleIntersection(intersect + (shadowOffset * lightRayDirection), lightRayDirection, triangles[k], tempTriangleIntersect, tempTriangleDist)) {
							shadow = false;
						}

					}
				}

				//adding colors with the lighting effects
				//sphere section
				if (colorThePixel == 1) {
					if (shadow) {
						glm::vec3 sphereNormal = glm::normalize(spheres[closestPixel].spherePos - intersect);
						glm::vec3 oppositeRayDirection = -rayDirection;

						glm::vec3 lightDirection = glm::normalize(intersect - lights[m].lightPos);
						glm::vec3 sphereReflection = glm::reflect(lightDirection, sphereNormal);

						float a = glm::dot(sphereNormal, lightDirection);
						float b = glm::dot(sphereReflection, oppositeRayDirection);

						if (a < 0) {
							a = 0;
						}
						if (b < 0) {
							b = 0;
						}

						b = pow(b, spheres[closestPixel].sphereShi);

						colorPixel += spheres[closestPixel].sphereAmb;
						glm::vec3 addingLight = lights[m].lightColor * (spheres[closestPixel].sphereDif * a + spheres[closestPixel].sphereSpe * b);
						colorPixel += addingLight;
					}
					else {
						colorPixel += spheres[closestPixel].sphereAmb;
					}

				}
				//triangle section
				else if (colorThePixel == 2) {
					if (shadow) {
						glm::vec3 triEdge1 = triangles[closestPixel].triV2 - triangles[closestPixel].triV1;
						glm::vec3 triEdge2 = triangles[closestPixel].triV3 - triangles[closestPixel].triV1;
						glm::vec3 triangleNormal = glm::normalize(glm::cross(triEdge1, triEdge2));
						triangleNormal = -triangleNormal;

						glm::vec3 oppositeRayDirection = -rayDirection;
						glm::vec3 lightDirection = glm::normalize(intersect - lights[m].lightPos);
						glm::vec3 triangleReflection = glm::reflect(lightDirection, triangleNormal);

						float a = glm::dot(triangleNormal, lightDirection);
						float b = glm::dot(triangleReflection, oppositeRayDirection);

						if (a < 0) {
							a = 0;
						}
						if (b < 0) {
							b = 0;
						}

						b = pow(b, triangles[closestPixel].triShi);


						colorPixel += triangles[closestPixel].triAmb;
						glm::vec3 addingLight = lights[m].lightColor * (triangles[closestPixel].triDif * a + triangles[closestPixel].triSpe * b);
						colorPixel += addingLight;

					}
					else {
						colorPixel += triangles[closestPixel].triAmb;
					}

				}
			}
			//if there is nothing in the way(no intersect), it will just return the background color which is black
			float color[3]{ colorPixel.x,colorPixel.y,colorPixel.z };
			picture.draw_point(j, i, color);


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

			Sphere newSphere(tempSpherePos, tempSphereRad, tempSphereAmb, tempSphereDif, tempSphereSpe, tempSphereShi);
			spheres.emplace_back(move(newSphere));


		}
		else if (line == "light") {

			getline(readFile, line);
			createLightPosition(line);
			getline(readFile, line);
			createLightColor(line);

			Light newLight(tempLightPosition, tempLightColor);
			lights.emplace_back(move(newLight));

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

			Triangle newTriangle(tempTriangleV1, tempTriangleV2, tempTriangleV3, tempTriangleAmb, tempTriangleDif, tempTriangleSpe, tempTriangleShi);
			triangles.emplace_back(move(newTriangle));

		}
		else if (line == "plane") {

			getline(readFile, line);
			createPlaneNormal(line);
			getline(readFile, line);
			createPlanePosition(line);
			getline(readFile, line);
			createPlaneAmbiance(line);
			getline(readFile, line);
			createPlaneDiffusion(line);
			getline(readFile, line);
			createPlaneSpecular(line);

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
void createCameraFOV(string result) {

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
	tempSpherePos = glm::vec3(a, b, c);
	//sphere.spherePos = glm::vec3(a, b, c);

}
void createSphereRadius(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	tempSphereRad = (stof(result));
	//sphere.rad = (stof(result));
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
	tempSphereAmb = glm::vec3(a, b, c);
	//sphere.sphereAmb = glm::vec3(a, b, c);

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
	tempSphereDif = glm::vec3(a, b, c);
	//sphere.sphereDif = glm::vec3(a, b, c);

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
	tempSphereSpe = glm::vec3(a, b, c);
	//sphere.sphereSpe = glm::vec3(a, b, c);

}
void createSphereShininess(string result) {

	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	tempSphereShi = (stof(result));
	//sphere.sphereShi = (stof(result));

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
		float a = stof(storing.at(1));
	float b = stof(storing.at(2));
	float c = stof(result);
	tempLightPosition = glm::vec3(a, b, c);

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
	tempLightColor = glm::vec3(a, b, c);
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
	tempTriangleV1 = glm::vec3(a, b, c);
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
	tempTriangleV2 = glm::vec3(a, b, c);
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
	tempTriangleV3 = glm::vec3(a, b, c);
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
	tempTriangleAmb = glm::vec3(a, b, c);
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
	tempTriangleDif = glm::vec3(a, b, c);
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
	tempTriangleSpe = glm::vec3(a, b, c);
}
void createTriangleShininess(string result) {
	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	tempTriangleShi = (stof(result));
}
void createPlaneNormal(string result) {
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
	plane.planeNorm = glm::vec3(a, b, c);
}
void createPlanePosition(string result) {
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
	plane.planePos = glm::vec3(a, b, c);
}
void createPlaneAmbiance(string result) {
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
	plane.planeAmb = glm::vec3(a, b, c);

}
void createPlaneDiffusion(string result) {
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
	plane.planeDif = glm::vec3(a, b, c);

}
void createPlaneSpecular(string result) {
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
	plane.planeSpe = glm::vec3(a, b, c);

}
void createPlaneShininess(string result) {
	string delimiter = " ";
	size_t pos = 0;
	std::vector<string> storing;
	while ((pos = result.find(delimiter)) != string::npos) {
		storing.emplace_back(result.substr(0, pos));
		result.erase(0, pos + delimiter.length());

	}
	
	plane.planeShi = (stof(result));

}
//reference https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
bool sphereIntersection(glm::vec3 spherePos, glm::vec3 camPos, glm::vec3 rayDir, float radians, glm::vec3& intersection, float& d) {//sphere intersection
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
//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm/ triangle intersection
bool triangleIntersection(glm::vec3 camPos, glm::vec3 rayVector, Triangle inTriangle, glm::vec3& intersection, float &d) {

	const float EPSILON = 0.0000001;

	glm::vec3 vertex1 = inTriangle.triV1;
	glm::vec3 vertex2 = inTriangle.triV2;
	glm::vec3 vertex3 = inTriangle.triV3;

	glm::vec3 edge1, edge2, h, s, q;

	float a, f, u, v;
	edge1 = vertex2 - vertex1;
	edge2 = vertex3 - vertex1;
	h = glm::cross(rayVector, edge2);
	a = glm::dot(edge1, h);

	if (a > -EPSILON && a < EPSILON)
		return false;
	f = 1 / a;
	s = camPos - vertex1;
	u = f * (glm::dot(s, h));
	if (u < 0.0 || u > 1.0)
		return false;
	q = glm::cross(s, edge1);
	v = f * glm::dot(rayVector, q);
	if (v < 0.0 || u + v > 1.0)
		return false;
	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * glm::dot(edge2, q);
	if (t > EPSILON) // ray intersection
	{
		intersection = camPos + rayVector * t;
		d = t;
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
		return false;

}
bool planeIntersection(glm::vec3 norm, glm::vec3 origin, glm::vec3 rayOrigin, glm::vec3 rayDirection,glm::vec3 pointOfIntersect, float &t) {

	norm = glm::normalize(norm);

	float denom = glm::dot(norm, rayDirection);
	if (abs(denom) > 1e-6) {
		glm::vec3 dist = origin - rayOrigin;
		t = glm::dot(dist, norm);
		pointOfIntersect = rayOrigin + rayDirection * t;
		
		return(t >= 0);

	}
	return false;
}
void displayObjectsAttributes() {

	cout << "Camera" << endl;
	cout << "Position: " << camera.camPos.x << " " << camera.camPos.y << " " << camera.camPos.z << endl;
	cout << "Field Of View: " << camera.fieldOfView << endl;
	cout << "Focal Length: " << camera.focalLength << endl;
	cout << "Aspect Ratio: " << camera.aspectRatio << endl;
	cout << endl;
	for (int i = 0; i < spheres.size(); i++) {
		cout << "Sphere" << endl;
		cout << "Position: " << spheres[i].spherePos.x << " " << spheres[i].spherePos.y << " " << spheres[i].spherePos.z << endl;
		cout << "Radius: " << spheres[i].rad << endl;
		cout << "Ambiance: " << spheres[i].sphereAmb.x << " " << spheres[i].sphereAmb.y << " " << spheres[i].sphereAmb.z << endl;
		cout << "Diffusion: " << spheres[i].sphereDif.x << " " << spheres[i].sphereDif.y << " " << spheres[i].sphereDif.z << endl;
		cout << "Specular: " << spheres[i].sphereSpe.x << " " << spheres[i].sphereSpe.y << " " << spheres[i].sphereSpe.z << endl;
		cout << "Shininess: " << spheres[i].sphereShi << endl;
		cout << endl;
	}
	for (int i = 0; i < lights.size(); i++) {
		cout << "Light" << endl;
		cout << "Position: " << lights[i].lightPos.x << " " << lights[i].lightPos.y << " " << lights[i].lightPos.z << endl;
		cout << "Color: " << lights[i].lightColor.x << " " << lights[i].lightColor.y << " " << lights[i].lightColor.z << endl;
		cout << endl;
	}
	cout << "Model" << endl;
	cout << "Model Name: " << model.modelFile << endl;
	cout << "Ambiance: " << model.modelAmb.x << " " << model.modelAmb.y << " " << model.modelAmb.z << endl;
	cout << "Diffusion: " << model.modelDif.x << " " << model.modelDif.y << " " << model.modelDif.z << endl;
	cout << "Specular: " << model.modelSpe.x << " " << model.modelSpe.y << " " << model.modelSpe.z << endl;
	cout << "Shininess: " << model.modelShi << endl;
	cout << endl;

	for (int i = 0; i < triangles.size(); i++) {
		cout << "Triangle" << endl;
		cout << "V1 coord: " << triangles[i].triV1.x << " " << triangles[i].triV1.y << " " << triangles[i].triV1.z << endl;
		cout << "V2 coord: " << triangles[i].triV2.x << " " << triangles[i].triV2.y << " " << triangles[i].triV2.z << endl;
		cout << "V3 coord: " << triangles[i].triV3.x << " " << triangles[i].triV3.y << " " << triangles[i].triV3.z << endl;
		cout << "Ambiance: " << triangles[i].triAmb.x << " " << triangles[i].triAmb.y << " " << triangles[i].triAmb.z << endl;
		cout << "Diffusion: " << triangles[i].triDif.x << " " << triangles[i].triDif.y << " " << triangles[i].triDif.z << endl;
		cout << "Specular: " << triangles[i].triSpe.x << " " << triangles[i].triSpe.y << " " << triangles[i].triSpe.z << endl;
		cout << "Shininess: " << triangles[i].triShi << endl;
		cout << endl;
	}

	cout << "Plane" << endl;
	cout << "Normal: " << plane.planeNorm.x << " " << plane.planeNorm.y << " " << plane.planeNorm.z << endl;
	cout << "Position: " << plane.planePos.x << " " << plane.planePos.y << " " << plane.planePos.z << endl;
	cout << "Ambiance: " << plane.planeAmb.x << " " << plane.planeAmb.y << " " << plane.planeAmb.z << endl;
	cout << "Diffusion: " << plane.planeDif.x << " " << plane.planeDif.y << " " << plane.planeDif.z << endl;
	cout << "Specular: " << plane.planeSpe.x << " " << plane.planeSpe.y << " " << plane.planeSpe.z << endl;
}