#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int det (int sizeM, int** a)
{
	if (sizeM==2) {
		return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	}
	else {
		int d=0;
		int** b;
	    b = (int**) malloc(sizeM * sizeof(int*));
	 
	    for (int i = 0; i < sizeM; i++) {
	        b[i] = (int*) malloc((i + 1) * sizeof(int));
	    }
		int z=-1;
		for (int i=0;i<sizeM;i++){
			for (int j=0;j<(sizeM-1);j++) {
				for (int k=0;k<(sizeM-1);k++){
					if (k<i) {
						b[j][k]=a[j+1][k];
					}
					else {
						b[j][k]=a[j+1][k+1];
					}
				}
			}
			z=z*(-1);
			d+=a[0][i]*det(sizeM-1,b)*z;
		}
		return d;
	}
}

void main (void)
{
	int n;
	do {
		printf("Put an number of quad matrix: \n");
		scanf("%d",&n);
	} while ((n<2)&&(n>99));
	int** A;
    A = (int**) malloc(n * sizeof(int*));
 
    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc((i + 1) * sizeof(int));
    }

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++)
	    {
	        A[i][j] = rand() % 10;
	        printf("%d ", A[i][j]);
	    }
	    printf("\n");
	}

	printf("Determinant A: %i\n", det(n,A));

	return;
}


