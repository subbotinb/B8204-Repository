#include "stdafx.h"

struct Matrix
{
  int n;
  int m;
  int** Mass;
};

Matrix Create_rand (int n, int m);
Matrix Create (int n, int m);
long double determ(Matrix Matr,int size);
Matrix Summ (Matrix Matr1,Matrix Matr2);
Matrix Dif (Matrix Matr1,Matrix Matr2);
Matrix Multiple (Matrix Matr1,Matrix Matr2);
void Print_Matrix (Matrix matr);