
#include "stdafx.h"
#include "TMatrix.h"
#include <iostream>
using namespace std;

Matrix Create (int n, int m)
{
  Matrix Matr;
  Matr.Mass = new int * [n];
  for (int i = 0; i < n; i++)
    Matr.Mass [i] = new int [m];
  Matr.n=n;
  Matr.m=m;

  return (Matr);
}

Matrix Create_rand (int n, int m)
{
  Matrix Matr = Create (n, m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)

      Matr.Mass [i][j] = ((rand() % 21 - 10));

  return (Matr);
}

long double determ(Matrix Matr)
{
  int size = Matr.n;
  int i,j;
  double det=0;
  int** matr;
  if(Matr.n==1)
  {
    det = Matr.Mass[0][0];
  }
  else if(Matr.n==2)
  {
    det=Matr.Mass[0][0]*Matr.Mass[1][1]-Matr.Mass[0][1]*Matr.Mass[1][0];
  }
  else
  {
    matr=new int*[Matr.n-1];
    for(i=0;i<Matr.n;++i)
    {
      for(j=0;j<Matr.n-1;++j)
      {
        if(j<i) 
          matr[j]=Matr.Mass[j];
        else
          matr[j] = Matr.Mass[j+1];
      }
      size -= 1;
      det+=pow((double)-1, (i+j))*determ(Matr)*Matr.Mass[i][size];
    }
    delete[] matr;
  }
  return det;
}

Matrix Multiple (Matrix Matr1,Matrix Matr2)
{
  Matrix Matr = Create (Matr1.n, Matr2.m); 

  for (int i = 0; i < Matr.n; i++) {
    for (int j = 0; j < Matr.m; j++) {

      int summ = 0;
      for (int c = 0; c < Matr.m; c++)
        summ += Matr1.Mass[i][c] * Matr2.Mass[c][j];
      Matr.Mass[i][j] = summ;
    }
  }

  return (Matr);
}

Matrix Summ (Matrix Matr1,Matrix Matr2)
{
  Matrix Matr = Create (Matr2.n, Matr2.m); 

  for(int i = 0; i < Matr.m; i++)   
    for(int j = 0; j < Matr.n; j++)

      Matr.Mass [i][j] = Matr1.Mass[i][j] + Matr2.Mass[i][j]; 

  return (Matr);
}

Matrix Dif (Matrix Matr1,Matrix Matr2)
{
  Matrix Matr = Create (Matr2.n, Matr2.m);

  for(int i=0; i<Matr.m; ++i)   
    for(int j=0; j<Matr.n; ++j)

      Matr.Mass [i][j] = Matr1.Mass [i][j] - Matr2.Mass [i][j];

  return Matr;
}

void Print_Matrix (Matrix matr)
{
  for(int i=0; i<matr.n; ++i)
  { 

    for(int j=0; j<matr.m; ++j)
    {
      printf("%4d",matr.Mass [i][j]);
    }
    cout << '\n';
  }
}
