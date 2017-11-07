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


#include <cmath>
#include <iostream>
#include <fstream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

//creating vectors
struct Vec3 {
	double x, y, z;
	Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

	//operators to simplify vector math
	Vec3 operator + (const Vec3& v) const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}
	Vec3 operator - (const Vec3& v) const {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}
	Vec3 operator * (double d) const {
		return Vec3(x*d, y*d, z*d);
	}
	Vec3 operator / (double d) const {
		return Vec3(x / d, y / d, z / d);
	}

	//getting normals
	Vec3 normalize() const {
		double mg = sqrt(x*x + y*y + z*z);
		return Vec3(x / mg, y / mg, z / mg);
	}

};

//dot-product of 2 vectors
inline double dot(const Vec3& a, const Vec3& b) {
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

//rays for ray-tracing
struct Ray {
	Vec3 o, d;
	Ray(const Vec3& o, const Vec3& d) : o(o), d(d) {}
};

//building sphere object
struct Sphere {
	Vec3 c;
	double r;
	Sphere(const Vec3& c, double r) : c(c), r(r) {}

	Vec3 getNormal(const Vec3& pi) const {
		return (pi - c) / r;
	}

	bool intersect(const Ray& ray, double &t) const {
		const Vec3 o = ray.o;
		const Vec3 d = ray.d;
		const Vec3 oc = o - c;
		const double b = 2 * dot(oc, d);
		const double c = dot(oc, oc) - r*r;
		double disc = b*b - 4 * c;
		if (disc < 1e-4) return false;
		disc = sqrt(disc);
		const double t0 = -b - disc;
		const double t1 = -b + disc;
		if (t0 < t1) {
			t = t0;
		}
		else {
			t = t1;
		}
		return true;
	}
};


void clamp255(Vec3& col) {
	if (col.x > 255) col.x = 255;
	if (col.x < 0) col.x = 0;
	if (col.y > 255) col.y = 255;
	if (col.y < 0) col.y = 0;
	if (col.z > 255) col.z = 255;
	if (col.z < 0) col.z = 0;
}

//int main()
//{
//	const int H = 500;
//	const int W = 500;
//
//	const Vec3 white(255, 255, 255);
//	const Vec3 black(0, 0, 0);
//	const Vec3 red(255, 0, 0);
//
//	const Sphere sphere(Vec3(W*0.5, H*0.5, 50), 50);
//	const Sphere sphere2(Vec3(W*0.5, H*0.5, 100), 100);
//	const Sphere light(Vec3(0, 0, 50), 1);
//
//	//Creates an image with three channels and sets it to black
//	cimg_library::CImg<float> image(H, W, 1, 3, 0);
//
//	//Compute the color of each pixel and assign it
//	double t;
//	Vec3 pix_col(black);
//
//	for (int y = 0; y < H; y++) {
//		for (int x = 0; x < W; x++) {
//			pix_col = black;
//
//			const Ray ray(Vec3(x, y, 0), Vec3(0, 0, 1));
//
//			if (sphere.intersect(ray, t)) {
//				const Vec3 rayVec = ray.o + ray.d*t;
//				const Vec3 L = light.c - rayVec;
//				const Vec3 N = sphere2.getNormal(rayVec);
//				const double dt = dot(L.normalize(), N.normalize());
//			}
//
//			if (sphere2.intersect(ray, t)) {
//				const Vec3 rayVec = ray.o + ray.d*t;
//				const Vec3 L = light.c - rayVec;
//				const Vec3 N = sphere2.getNormal(rayVec);
//				const double dt = dot(L.normalize(), N.normalize());
//
//				pix_col = (red + white*dt) * 0.5;
//				clamp255(pix_col);
//			}
//
//			image(x, y) = pix_col.x, pix_col.y;
//		}
//	}
//	image.save("render.bmp");
//
//	cimg_library::CImgDisplay main_disp(image, "Render");
//	while (!main_disp.is_closed())
//		main_disp.wait();
//}