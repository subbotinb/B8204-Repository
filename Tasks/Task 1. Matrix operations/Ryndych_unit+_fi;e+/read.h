#pragma once
#include <iostream>
#include <fstream>

struct masInfo {
	int **mas;
	int masColum, masStr;
};

void nullMas(masInfo &Info);
bool readMas(masInfo &Info, std::ifstream &fi);