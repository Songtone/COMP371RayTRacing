#ifndef GENERATESCENE_H
#define GENERATESCENE_H

#include <iostream>
#include <string>
#include <fstream>
//#include "glm.hpp"

using namespace std;

class GenerateScene {
public:
	GenerateScene(const char* sceneFile) {

		string read;
		ifstream readSceneFile(sceneFile);
		if(readSceneFile.is_open()){
			//go through the file while dividing the attributes of each objects
		}

	}
};









#endif // !GENERATESCENE_H

