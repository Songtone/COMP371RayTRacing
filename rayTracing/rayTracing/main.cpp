#include "stdafx.h"
//#include <iostream>
//#include "CImg.h"
//#include "..\glm\glm.hpp"
//
////used this website to learn about ray tracing https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
//
//using namespace std;
//using namespace cimg_library;
//
//float pi = 3.1415965;
//
//float height;
//float width;
//
//float camPixelX;
//float camPixelY;
//
//float cameraPosX;
//float cameraPosY;
//float cameraPosZ;
//float cameraFOV;
//float cameraFocalLength;
//float cameraAspectRatio;
//
//
//int main() {
//	//sceneObject file hard coded variables
//	cameraPosX = 0.0f;
//	cameraPosY = 0.0f;
//	cameraPosZ = 0.0f;
//	cameraFOV = 60.0f;
//	cameraFocalLength = 1000.0f;
//	cameraAspectRatio = 1.33f;
//	glm::vec3 camera(cameraPosX,cameraPosY,cameraPosZ);
//	glm::vec3 rayDirection;
//
//	//finding the height and width of the display
//	
//	height = 2 * (cameraFocalLength*glm::tan(glm::radians(cameraFOV) / 2));
//	width = cameraAspectRatio*height;
//	CImg<float> image(width, height, 1, 3, 0);
//
//	//starting rayTracing
//	for (int i = 0; i < height; i++) {//for the height of the image, we will go through every pixel in that width. then go to the next height
//		for (int j = 0; j < width; j++) {
//			
//			camPixelX = (2 * ((j + 0.5) / width) - 1)*tan(cameraFOV / 2 * pi / 180)*cameraAspectRatio;
//			camPixelY = (1 - 2 * ((i + 0.5) / height))*tan(cameraFOV / 2 * pi / 180);
//
//			rayDirection = glm::vec3(camPixelX, camPixelY, - 1) - camera;
//			rayDirection = glm::normalize(rayDirection);
//
//			glm::vec3 pixelColor(0.2f);
//
//			
//		}
//
//	}
//	
//
//	//displays the scene in a window
//	CImgDisplay sceneDisp(image, "Current Scene");
//	image.normalize(0, 255);
//	image.save("picture");
//
//	system("pause");
//}

//
//#include "stdafx.h"
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <fstream>
//#include "..\glm\glm.hpp"
//#include <random>
//#include <functional>
//#include <vector>
//
//#include "CImg.h"
//
//using namespace cimg_library;
//using namespace std;
//
//int NumOfObjects;
//
//
////Camera temp Stuff
//glm::vec3 cameraPosition;
//float FOV;
//float focal_lenght;
//float aspect_ratio;
//
////Sphere temp Stuff
//glm::vec3 spherePosition;
//float rad;
//glm::vec3 sphereAmbiantColor;
//glm::vec3 sphereDiffuseColor;
//glm::vec3 sphereSpectColor;
//float sphereShine;
//
////Light temp stuff
//glm::vec3 lightPosition;
//glm::vec3 lightColor;
//
////HeightMap temp stuff
//string name;
//glm::vec3 mapAmbiantColor;
//glm::vec3 mapDiffuseColor;
//glm::vec3 mapSpectColor;
//float mapShine;
//
//
//struct Camera
//{
//	glm::vec3 cameraPosition;
//	float FOV;
//	float focal_lenght;
//	float aspect_ratio;
//	Camera() {}
//	Camera(glm::vec3 cp, float fov, float fl, float ar) : cameraPosition(cp), FOV(fov), focal_lenght(fl), aspect_ratio(ar) {}
//};
//
//struct Light
//{
//	glm::vec3 lightPosition;
//	glm::vec3 lightColor;
//
//	Light(glm::vec3 lp, glm::vec3 lc) : lightPosition(lp), lightColor(lc) {}
//};
//
//inline double dot(const glm::vec3& a, const glm::vec3& b) {
//	return (a.x*b.x + a.y*b.y + a.z*b.z);
//}
//
//struct Ray {
//	glm::vec3 o, d;
//	Ray(const glm::vec3& o, const glm::vec3& d) : o(o), d(d) {}
//};
//
//struct Sphere {
//	glm::vec3 spherePosition;
//	float rad;
//	glm::vec3 sphereAmbiantColor;
//	glm::vec3 sphereDiffuseColor;
//	glm::vec3 sphereSpectColor;
//	float sphereShine;
//
//	Sphere(glm::vec3 sp, float r, glm::vec3 sa, glm::vec3 sd, glm::vec3 ssc, float ss)
//		: spherePosition(sp), rad(r), sphereAmbiantColor(sa), sphereDiffuseColor(sd), sphereSpectColor(ssc), sphereShine(ss) {}
//
//	glm::vec3 getNormal(const glm::vec3& pi) const { return (pi - spherePosition) / rad; }
//
//	bool intersect(const Ray& ray, double &t) const
//	{
//		const glm::vec3 o = ray.o;
//		const glm::vec3 d = ray.d;
//		const glm::vec3 oc = o - spherePosition;
//		const double b = 2 * dot(oc, d);
//		const double c = dot(oc, oc) - rad*rad;
//		double disc = b*b - 4 * c;
//		if (disc < 1e-4) return false;
//		disc = sqrt(disc);
//		const double t0 = -b - disc;
//		const double t1 = -b + disc;
//		t = (t0 < t1) ? t0 : t1;
//		return true;
//	}
//};
//
//void clamp255(glm::vec3& col) {
//	col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
//	col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
//	col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
//}
//
//glm::vec3 normalize(glm::vec3 VEC)
//{
//	double mg = sqrt(VEC.x*VEC.x + VEC.y*VEC.y + VEC.z*VEC.z);
//	return glm::vec3(VEC.x / mg, VEC.y / mg, VEC.z / mg);
//}
//
//glm::vec3 powerUpColor(glm::vec3 Original)
//{
//	return glm::vec3(Original.r * 255, Original.g * 255, Original.b * 255);
//}

//int main()
//{
//	vector<Sphere> spheres;
//	vector<Light> lights;
//	Camera camera;
//
//	//File realated stuff
//#pragma region
//	ifstream inFile;
//	inFile.open("sceneObject.txt");
//	if (!inFile)
//	{
//		cerr << "Unable to open file datafile.txt";
//		exit(1);
//	}
//
//	string type;
//	string garbage;
//	inFile >> NumOfObjects;
//
//	while (inFile.good())
//	{
//		inFile >> type;
//		if (type == "camera")
//		{
//			inFile >> garbage;
//			inFile >> cameraPosition.x;
//			inFile >> cameraPosition.y;
//			inFile >> cameraPosition.z;
//			inFile >> garbage;
//			inFile >> FOV;
//			inFile >> garbage;
//			inFile >> focal_lenght;
//			inFile >> garbage;
//			inFile >> aspect_ratio;
//			camera = Camera(cameraPosition, FOV, focal_lenght, aspect_ratio);
//		}
//		if (type == "sphere")
//		{
//			inFile >> garbage;
//			inFile >> spherePosition.x;
//			inFile >> spherePosition.y;
//			inFile >> spherePosition.z;
//			inFile >> garbage;
//			inFile >> rad;
//			inFile >> garbage;
//			inFile >> sphereAmbiantColor.x;
//			inFile >> sphereAmbiantColor.y;
//			inFile >> sphereAmbiantColor.z;
//			inFile >> garbage;
//			inFile >> sphereDiffuseColor.x;
//			inFile >> sphereDiffuseColor.y;
//			inFile >> sphereDiffuseColor.z;
//			inFile >> garbage;
//			inFile >> sphereSpectColor.x;
//			inFile >> sphereSpectColor.y;
//			inFile >> sphereSpectColor.z;
//			inFile >> garbage;
//			inFile >> sphereShine;
//			spheres.push_back(Sphere(spherePosition, rad, sphereAmbiantColor, sphereDiffuseColor, sphereSpectColor, sphereShine));
//		}
//		if (type == "light")
//		{
//			inFile >> garbage;
//			inFile >> lightPosition.x;
//			inFile >> lightPosition.y;
//			inFile >> lightPosition.z;
//			inFile >> garbage;
//			inFile >> lightColor.x;
//			inFile >> lightColor.y;
//			inFile >> lightColor.z;
//			lights.push_back(Light(lightPosition, lightColor));
//		}
//		if (type == "model")
//		{
//			inFile >> name;
//			inFile >> garbage;
//			inFile >> mapAmbiantColor.x;
//			inFile >> mapAmbiantColor.y;
//			inFile >> mapAmbiantColor.z;
//			inFile >> garbage;
//			inFile >> mapDiffuseColor.x;
//			inFile >> mapDiffuseColor.y;
//			inFile >> mapDiffuseColor.z;
//			inFile >> garbage;
//			inFile >> mapSpectColor.x;
//			inFile >> mapSpectColor.y;
//			inFile >> mapSpectColor.z;
//			inFile >> garbage;
//			inFile >> mapShine;
//		}
//	}
//	inFile.close();
//#pragma endregion
//
//
//
//	const int H = 500;
//	const int W = 500;
//
//	const glm::vec3 white(255, 255, 255);
//	const glm::vec3 black(0, 0, 0);
//
//
//	//Creates an image with three channels and sets it to black
//	cimg_library::CImg<float> image(H, W, 1, 3, 0);
//
//	//Compute the color of each pixel and assign it …
//
//	double t;
//	glm::vec3 pixelColor(black);
//
//	for (int y = 0; y < H; ++y)
//	{
//		for (int x = 0; x < W; ++x)						//For all pixels to display
//		{
//			pixelColor = black;							// put all pixels black them black
//			const Ray ray(glm::vec3(x, y, 0), glm::vec3(0, 0, 1)); // Cast a ray
//			for (int s = 0; s < spheres.size(); s++)
//			{
//				for (int l = 0; l < lights.size(); l++)
//				{
//					if (spheres[s].intersect(ray, t))				//If the ray intersects the sphere
//					{
//						glm::vec3 pi = ray.o + glm::vec3(ray.d.x*t, ray.d.y*t, ray.d.z*t);
//						glm::vec3 L = lights[l].lightPosition - pi;
//						glm::vec3 N = spheres[s].getNormal(pi);
//						L = normalize(L);
//						N = normalize(N);
//						const double dt = dot(L, N);
//						pixelColor = glm::vec3(white.x * dt, white.y * dt, white.z * dt);
//						pixelColor = pixelColor + powerUpColor(spheres[s].sphereAmbiantColor);
//						clamp255(pixelColor);					//max out color
//					}
//					image(x, y, 0) = pixelColor.r;//map Calculated pixel to output (image)
//					image(x, y, 1) = pixelColor.g;//map Calculated pixel to output (image)
//					image(x, y, 2) = pixelColor.b;//map Calculated pixel to output (image)
//				}
//			}
//
//
//		}
//	}
//
//
//	//Save out the image in BMP format. Pixel values must be in the range [0,255]
//	image.save("render.bmp");
//	//Display the rendered image on screen
//	cimg_library::CImgDisplay main_disp(image, "Render");
//
//	while (!main_disp.is_closed())
//		main_disp.wait();
//}