#pragma once
#include "read.h"

masInfo operator*(masInfo a1, masInfo a2);
masInfo operator-(masInfo a1, masInfo a2);
masInfo operator+(masInfo a1, masInfo a2);
void GetMatr(int **mas, int **p, int i, int j, int m);
int Determinant(int **mas, int m);
void writeMas(masInfo info);