#ifndef GENERATESCENE_H
#define GENERATESCENE_H

#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "model.h"
#include "triangle.h"


Camera camera;
Sphere sphere;
Light light;
Triangle triangle;
Model model;

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
