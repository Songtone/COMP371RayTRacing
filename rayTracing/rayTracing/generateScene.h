#ifndef GENERATESCENE_H
#define GENERATESCENE_H

#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "model.h"
#include "triangle.h"
#include <vector>

using namespace std;


Camera camera;
vector <Sphere> spheres;
//vector <Light> lights;
//vector <Triangle> triangles;
//vector <Model> models;
//Sphere sphere;
Light light;
Triangle triangle;
Model model;

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

bool sphereIntersection(glm::vec3 objectPos, glm::vec3 camPos, glm::vec3 ray, float radians,glm::vec3& intersection, float &distance);

void readTextFile(string fileName);
void displayObjectsAttributes();

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
#endif // !GENERATESCENE_H
