// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct masInfo {
	int **mas;
	int masColum, masStr;
};
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
				if (fi.eof()) { cout << "eof file";  return false; }
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

masInfo operator*(masInfo a1, masInfo a2) {
	if (a1.masStr != a2.masColum) cout << "\n Impossible to multiplacate matrix with different number of column in 1 and line in 2\n";
	else {
		masInfo res;
		res.masColum = a1.masColum;
		res.masStr = a2.masStr;
		nullMas(res);
		for (int i = 0; i < res.masColum; i++) {
			for (int j = 0; j < res.masStr; j++) {
				for (int k = 0; k < a1.masStr; k++)
					res.mas[i][j] += a1.mas[i][k] * a2.mas[k][j];
			}
		}
		return res;
	}
}
masInfo operator-(masInfo a1, masInfo a2) {
	if ((a1.masColum != a2.masColum) || (a1.masStr != a2.masStr)) cout << "\n Impossible to substract matrix with different size\n";
	else {
		masInfo res;
		res.masColum = a1.masColum;
		res.masStr = a1.masStr;
		nullMas(res);

		for (int i = 0; i < res.masColum; i++) {
			for (int j = 0; j < res.masStr; j++) {
				res.mas[i][j] = a1.mas[i][j] - a2.mas[i][j];
			}
		}
		return(res);
	}
}
masInfo operator+(masInfo a1, masInfo a2) {
	if ((a1.masColum != a2.masColum) || (a1.masStr != a2.masStr)) cout << "\n Impossible to sum matrix with different size\n";
	else {
		masInfo res;
		res.masColum = a1.masColum;
		res.masStr = a1.masStr;
		nullMas(res);

		for (int i = 0; i < res.masColum; i++) {
			for (int j = 0; j < res.masStr; j++) {
				res.mas[i][j] = a1.mas[i][j] + a2.mas[i][j];
			}
		}
		return(res);
	}
}
void GetMatr(int **mas, int **p, int i, int j, int m) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki<m - 1; ki++) { // �������� ������� ������
		if (ki == i)  di = 1;
		dj = 0;
		for (kj = 0; kj<m - 1; kj++) { // �������� ������� �������
			if (kj == j)  dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
int Determinant(int **mas, int m) {
	int i, j, d, k, n;
	int **p;
	p = new int*[m];
	for (i = 0; i<m; i++)
		p[i] = new int[m];
	j = 0; d = 0;
	k = 1; //(-1) � ������� i
	n = m - 1;
	if (m<1)  cout << "Impossible to get det";
	if (m == 1) {
		d = mas[0][0];
		return(d);
	}
	if (m == 2) {
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m>2) {
		for (i = 0; i<m; i++) {
			GetMatr(mas, p, i, 0, m);
			d = d + k * mas[i][0] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}

void writeMas(masInfo info) {
	for (int i = 0; i < info.masColum; i++) {
		for (int j = 0; j < info.masStr; j++)
			cout << info.mas[i][j] << " ";
		cout << "\n";
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	masInfo mas1Info;
	masInfo mas2Info;
	ifstream fi("input.txt");
	if (!fi.is_open()) cout << "file doesnt exist";
	else {
		if (readMas(mas1Info, fi)&&readMas(mas2Info, fi))
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

