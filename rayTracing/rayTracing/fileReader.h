#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include "generateScene.h"

using namespace std;

void sceneLoader(string fileName) {

	string file = fileName;
	string line;

	fstream readFile(file); 
		if (readFile.is_open()) {
			while (getline(readFile, line)) {
				if (line == "camera") {
					getline(readFile, line)
				}
			}
			readFile.close();
		}
	

}
#endif // !FILEREADER_H

