// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdafx.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "read.h"
#include "operations.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	masInfo mas1Info;
	masInfo mas2Info;
	ifstream fi("input.txt");
	if (!fi.is_open()) cout << "file doesnt exist";
	else {
		if (readMas(mas1Info,fi)&&readMas(mas2Info, fi))
		{
			writeMas(mas1Info);
			writeMas(mas2Info);
			cout << "\n";
			cout << "Sum\n";
			writeMas(mas1Info + mas2Info);
			cout << "Sub\n";
			writeMas(mas1Info - mas2Info);
			cout << "Mult\n";
			writeMas(mas1Info*mas2Info);
			if (mas1Info.masColum = mas1Info.masStr)
				cout << "Det\n" << Determinant(mas1Info.mas, mas1Info.masColum);
			else
				cout << "impossible to get det";
			system("pause");
			return 0;

		}
		
		fi.close();
	}
	

	}

