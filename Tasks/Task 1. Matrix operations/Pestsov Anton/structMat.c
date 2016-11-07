#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100 //размерность массива

typedef struct matrix_t {
   	unsigned int x,y;
   	float** mat;
}matrix;

//typedef struct matrix_t matrix;

void randPrint (int x1, int y1, float** A)
{
	float a = 5.0;
	for (int i = 0; i < x1; i++) {
	for (int j = 0; j < y1; j++)
	{
	    A[i][j] = ((float)rand()/(float)(RAND_MAX)) * a;//rand() % 10;
	    printf("%f ", A[i][j]);
	}
	printf("\n");
	}
}

void summ (int x1, int y1, int x2, int y2, float** A, float** B)
{
	if ((x1==x2)&&(y1==y2)){
		float** C;
		C=(float**) malloc(x1 * sizeof(float*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (float*) malloc((i + 1) * sizeof(float));
		}
		printf("result: A+B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y1; j++)
		    {
		        C[i][j] = A[i][j]+B[i][j];
		        printf("%f ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't summ matrix with this values");
	}
}

void diff (int x1, int y1, int x2, int y2, float** A, float** B)
{
	if ((x1==x2)&&(y1==y2)){
		float** C;
		C=(float**) malloc(x1 * sizeof(float*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (float*) malloc((i + 1) * sizeof(float));
		}
		printf("result: A+B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y1; j++)
		    {
		        C[i][j] = A[i][j]-B[i][j];
		        printf("%f ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't summ matrix with this values");
	}
}

void mult (int x1, int y1, int x2, int y2, float** A, float** B)
{
	if (y1==x2){
		float** C;
		C=(float**) malloc(x1 * sizeof(float*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (float*) malloc((i + 1) * sizeof(float));
		}
		printf("result: A*B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y2; j++)
		    {
		    	C[i][j] = 0;
		        for(int k=0;k<x2;k++){
		        	C[i][j]+=A[i][k]*B[k][j];
		        }
		        printf("%f ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't mult matrix with this values");
	}
}

void main (void)
{

	matrix A,B;
	do {
		printf("Put number of strings matrix A= \n");	
		scanf("%d",&A.x);
		printf("Put number of column matrix A= \n");	
		scanf("%d",&A.y);
		printf("Put number of strings matrix B= \n");	
		scanf("%d",&B.x);
		printf("Put number of column matrix B= \n");	
		scanf("%d",&B.y);
		if ((A.x>N)||(B.x>N)||(A.y>N)||(B.y>N))
			printf("Invalid value of array, put right numbers");
	} while ((A.x>N)||(B.x>N)||(A.y>N)||(B.y>N));

	A.mat=(float**) malloc(A.x * sizeof(float*));
	for (int i = 0; i < A.y; i++) {
	    A.mat[i] = (float*) malloc((i + 1) * sizeof(float));
	}

	B.mat=(float**) malloc(B.x * sizeof(float*));
	for (int i = 0; i < B.y; i++) {
	    B.mat[i] = (float*) malloc((i + 1) * sizeof(float));
	}

	printf("matrix A\n");
	srand((unsigned int)time(NULL));
	randPrint(A.x,A.y,A.mat);

	printf("matrix B\n");
	randPrint(B.x,B.y,B.mat);

	char op = 0;

	do {
		printf("Choose a operation (* mult,+ summ,- dif) ");	
		scanf("%c",&op);
	} while ((op!='*')&&(op!='+')&&(op!='-'));

	switch (op)
	{
		case '+':
			summ(A.x,A.y,B.x,B.y,A.mat,B.mat);
			break;
		case '-':
			diff(A.x,A.y,B.x,B.y,A.mat,B.mat);
			break;
		case '*':
			mult(A.x,A.y,B.x,B.y,A.mat,B.mat);
			break;
	}

	return;
}