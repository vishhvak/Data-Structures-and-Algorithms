//Thread Scheduling using omp parallel for schedule - Static
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int i, j, n = 100, m = 100;
	int a[100][100], b[100][100], c[100][100];	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			a[i][j] = i;
			b[i][j] = j;
		}
	}
	//To Print and see the matrices
	/*printf("\nPrinting A Matrix\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)  
			printf("\t%d",a[i][j]);
		printf("\n");
	}
	printf("\nPrinting B Matrix\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)  
			printf("\t%d",b[i][j]);
		printf("\n");
	}*/	
	#pragma omp parallel for schedule(static)
	for(i = 0; i < n; i++) 
		for(j = 0; j < m; j++) 
			c[i][j] = a[i][j] + b[i][j];

	/* To Print Sum Matrix	
	printf("\nPrinting Sum Matrix\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)  
			printf("\t%d",c[i][j]);
		printf("\n");
	}*/
}

/*Execution Time

Sequential -
real	0m0.001s
user	0m0.000s
sys		0m0.001s

OpenMP
real	0m0.006s
user	0m0.027s
sys		0m0.001s
*/



