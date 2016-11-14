
#include "stdafx.h"
#include "TMatrix.h"
#include <iostream>
using namespace std;



void Create (Matrix &Matr , int n, int m)
{
 Matr.Mass = new  int * [n];
 for (int i = 0; i<n ; i++)
	 Matr.Mass [i] = new int [m];

Matr.m = m;
Matr.n = n;
}

void Create_rand (Matrix &Matr , int n, int m)
{
Create(Matr , n,m);
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
     Matr.Mass [i][j] = ((rand() % 21 - 10));

}



long double determ(int** Arr, int size)
{
        int i,j;
        double det=0;
        int** matr;
        if(size==1)
        {
          det=Arr[0][0];
        }
        else if(size==2)
        {
          det=Arr[0][0]*Arr[1][1]-Arr[0][1]*Arr[1][0];
        }
        else
        {
          matr=new int*[size-1];
          for(i=0;i<size;++i)
          {
            for(j=0;j<size-1;++j)
            {
              if(j<i) 
                matr[j]=Arr[j];
              else
                matr[j]=Arr[j+1];
            }
          det+=pow((double)-1, (i+j))*determ(matr, size-1)*Arr[i][size-1];
          }
        delete[] matr;
        }
        return det;
}

void Multiplication (Matrix Matr1,Matrix Matr2,Matrix &matr_rez)
{
      Create (matr_rez,Matr1.n,Matr2.m);

      for (int i = 0; i < Matr1.n; i++) {
      for (int j = 0; j < Matr2.m; j++) {
                  
      int summ = 0;
      for (int c = 0; c < Matr1.m; c++)
        summ += Matr1.Mass[i][c] * Matr2.Mass[c][j];
      matr_rez.Mass[i][j] = summ;
            }
      }
}

void Summ (Matrix Matr1,Matrix Matr2,Matrix &matr_rez)
{
   Create (matr_rez, Matr1.n,Matr2.m);

    for(int i = 0; i < Matr1.m; i++)   
    for(int j = 0; j < Matr1.n; j++)
       
      matr_rez.Mass [i][j] = Matr1.Mass[i][j] + Matr2.Mass[i][j]; 
}

void Dif (Matrix Matr1,Matrix Matr2,Matrix &matr_rez)
{
    Create (matr_rez, Matr2.n,Matr2.m);

    for(int i=0; i<Matr1.m; ++i)   
    for(int j=0; j<Matr1.n; ++j)

      matr_rez.Mass [i][j] = Matr1.Mass [i][j] - Matr2.Mass [i][j];
}

void Print_Matrix (Matrix matr,int n,int m)
{
  for(int i=0; i<n; ++i)
  { 
      
    for(int j=0; j<m; ++j)
    {
      printf("%4d",matr.Mass [i][j]);
    }
    cout << '\n';
  }
}
