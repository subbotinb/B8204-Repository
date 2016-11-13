#include "stdafx.h"

struct Matrix
{
  int n;
  int m;
  int** Mass;
};

Matrix Create_rand (int n, int m);//Создание матрицы с рандомными значениями
Matrix Create (int n, int m);//Создание матрицы
long double determ(Matrix Matr,int size);//Определитель
Matrix Summ (Matrix Matr1,Matrix Matr2);//Сложение
Matrix Dif (Matrix Matr1,Matrix Matr2);//Вычитание
Matrix Multiple (Matrix Matr1,Matrix Matr2);//Умножение
void Print_Matrix (Matrix matr); //Печать