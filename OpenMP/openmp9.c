//Printing integers from 1 to 10000 using omp parallel for
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int i, n = 100000001;
	#pragma omp parallel for schedule(static,12500000)
	for(i = 1; i < n; i++) {
		printf("%d\n",i);
	}
}
