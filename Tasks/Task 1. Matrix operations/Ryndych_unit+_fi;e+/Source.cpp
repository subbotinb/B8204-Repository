#include "stdafx.h"
#include <stdio.h>

#include "read.h"
using namespace std;

void nullMas(masInfo &Info) {
	Info.mas = new int*[Info.masColum];
	for (int count = 0; count < Info.masColum; count++) {
		Info.mas[count] = new int[Info.masStr];
	}
	for (int i = 0; i < Info.masColum; i++) {
		for (int j = 0; j < Info.masStr; j++) {
			Info.mas[i][j] = 0;
		}
	}
}
bool readMas(masInfo &Info, ifstream &fi) {
	Info.masColum = 0;
	Info.masStr = 0;
	fi >> Info.masColum >> Info.masStr;
	if ((Info.masColum != 0) || (Info.masStr != 0)) {
		nullMas(Info);
		for (int i = 0; i < Info.masColum; i++) {
			for (int j = 0; j < Info.masStr; j++) {
				if (fi.eof()) { 
					cout << "eof file";
					system("pause");
					return false; 
				}
				else
					fi >> Info.mas[i][j];
			}
		}
	}
	else
	{
		cout << "eof file";
		return false;
	}

}
