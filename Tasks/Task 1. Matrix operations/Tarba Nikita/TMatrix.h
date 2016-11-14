#include "stdafx.h"

struct Matrix
{
  int n;
  int m;
  int** Mass;
};

long double determ(int** Arr, int size);//Определитель
void Summ (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//Сложение
void Dif (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//Вычитание
void Multiplication (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//Умножение
void Print_Matrix (Matrix matr,int n,int m); //Печать
void Create (Matrix &Matr , int n, int m); //создание матрицы
void Create_rand (Matrix &Matr , int n, int m);