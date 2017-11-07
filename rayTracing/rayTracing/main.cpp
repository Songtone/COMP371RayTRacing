#include "stdafx.h"
#include <iostream>
#include "CImg.h"
#include "..\glm\glm.hpp"

//used this website to learn about ray tracing https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays

using namespace std;
using namespace cimg_library;

//hard coded variable values
float pi = 3.1415965;

float height;
float width;

float camPixelX;
float camPixelY;

float cameraPosX;
float cameraPosY;
float cameraPosZ;
float cameraFOV;
float cameraFocalLength;
float cameraAspectRatio;


int main() {
	//sceneObject file hard coded variables
	cameraPosX = 0.0f;
	cameraPosY = 0.0f;
	cameraPosZ = 0.0f;
	cameraFOV = 60.0f;
	cameraFocalLength = 1000.0f;
	cameraAspectRatio = 1.33f;
	glm::vec3 camera(0.0f);
	glm::vec3 rayDirection;

	//finding the height and width of the display
	
	height = 2 * (cameraFocalLength*glm::tan(glm::radians(cameraFOV) / 2));
	width = cameraAspectRatio*height;
	CImg<float> image(width, height, 1, 3, 0);

	//starting rayTracing
	for (int i = 0; i < height; i++) {//for the height of the image, we will go through every pixel in that width. then go to the next height
		for (int j = 0; j < width; j++) {
			
			camPixelX = (2 * ((j + 0.5) / width) - 1)*tan(cameraFOV / 2 * pi / 180)*cameraAspectRatio;
			camPixelY = (1 - 2 * ((i + 0.5) / height))*tan(cameraFOV / 2 * pi / 180);

			rayDirection = glm::vec3(camPixelX, camPixelY, - 1) - camera;
			rayDirection = glm::normalize(rayDirection);

			glm::vec3 pixelColor(0.2f);

			image.draw_point(i, j, pixelColor);
		}

	}
	

	//displays the scene in a window
	CImgDisplay sceneDisp(image, "Current Scene");
	image.normalize(0, 255);
	image.save("picture");

	system("pause");
}