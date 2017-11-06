#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
string line;

int main()
{
	ifstream readObjectFile("sceneObject.txt");
	if (readObjectFile.is_open()) {
		while (getline(readObjectFile, line)) {
			cout << line << endl;
		}
		readObjectFile.close();
	}
	system("pause");
	return 0;
}
