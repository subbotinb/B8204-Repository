// Матрицы.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"

#include <iostream>
#include <ctime>

using namespace std;

int _tmain(){ 
	Matrix M1,M2,m_rzlt;
	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)));
	cout << "Введите количество строк и количество столбцов:\n";
	cin >> M1.n >> M1.m;

	M1 = Create_rand (M1.n, M1.m);

	Print_Matrix (M1);

	if (M1.n==M1.m) 
	{
		cout << determ(M1,M1.n);
		cout << endl;
	}

	cout << "Введите количество строк и количество столбцов 2-ой матрицы:\n";
	cin >> M2.n >> M2.m;

	M2 = Create_rand (M2.n, M2.m);

	Print_Matrix (M2);

	if (M2.n==M2.m) 
	{
		cout << determ(M2,M2.n);
		cout << endl;
	}

	if ((M1.n==M2.n) & (M1.m==M2.m))
	{  
		m_rzlt = Summ (M1,M2);  
		cout << "Сумма равна:\n";
		Print_Matrix(m_rzlt);
		delete [] m_rzlt.Mass;

		m_rzlt = Dif (M1,M2);	 
		cout << "Разность равна:\n";
		Print_Matrix(m_rzlt);
		delete [] m_rzlt.Mass;
	}


	if (M1.m==M2.n)
	{
		m_rzlt = Multiple (M1,M2);
		cout << "Произведение равно:\n";
		Print_Matrix(m_rzlt);
		delete [] m_rzlt.Mass;
	}

	delete []  M1.Mass; delete []  M2.Mass;

	system("pause");
	return 0;
}


