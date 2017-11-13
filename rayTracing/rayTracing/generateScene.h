#ifndef GENERATESCENE_H
#define GENERATESCENE_H

#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "model.h"
#include "triangle.h"
#include "plane.h"
#include <vector>

using namespace std;


Camera camera;
vector <Sphere> spheres;
vector <Light> lights;
vector <Triangle> triangles;
Plane plane;
Model model;

//temporary variables to hold values.
glm::vec3 tempSpherePos;
float tempSphereRad;
glm::vec3 tempSphereDif;
glm::vec3 tempSphereAmb;
glm::vec3 tempSphereSpe;
float tempSphereShi;

glm::vec3 tempLightPosition;
glm::vec3 tempLightColor;

string tempModelFile;
glm::vec3 tempModelAmb;
glm::vec3 tempModelDif;
glm::vec3 tempModelSpe;
float tempModelShi;

glm::vec3 tempTriangleV1;
glm::vec3 tempTriangleV2;
glm::vec3 tempTriangleV3;
glm::vec3 tempTriangleAmb;
glm::vec3 tempTriangleDif;
glm::vec3 tempTriangleSpe;
float tempTriangleShi;

//functions being used to determine the intersections
bool sphereIntersection(glm::vec3 objectPos, glm::vec3 camPos, glm::vec3 ray, float radians,glm::vec3& intersection, float &distance);
bool triangleIntersection(glm::vec3 camPos, glm::vec3 rayVector, Triangle inTriangle, glm::vec3& intersection, float &d);
bool planeIntersection(glm::vec3 norm, glm::vec3 origin, glm::vec3 rayOrigin, glm::vec3 rayDirection, glm::vec3 pointOfIntersect, float &t);

//functions to read and display the information on the text file.
void readTextFile(string fileName);
void displayObjectsAttributes();


//all the functions used to parse the info.
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

void createTriangleV1(string result);
void createTriangleV2(string result);
void createTriangleV3(string result);
void createTriangleAmbiance(string result);
void createTriangleDiffusion(string result);
void createTriangleSpecular(string result);
void createTriangleShininess(string result);

void createModelName(string result);
void createModelAmbiance(string result);
void createModelDiffusion(string result);
void createModelSpecular(string result);
void createModelShininess(string result);

void createPlaneNormal(string result);
void createPlanePosition(string result);
void createPlaneAmbiance(string result);
void createPlaneDiffusion(string result);
void createPlaneSpecular(string result);
void createPlaneShininess(string result);
#endif // !GENERATESCENE_H
