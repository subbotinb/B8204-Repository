#include "read.h"
#include "stdafx.h"
#include "operations.h"
using namespace std;

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
	for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
		if (ki == i)  di = 1;
		dj = 0;
		for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
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
	k = 1; //(-1) в степени i
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
