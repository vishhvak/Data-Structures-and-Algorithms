#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int i,j;
	#pragma omp parallel for num_threads(2) collapse(2)
	for(i=0;i<4;i++)
 		for(j=0;j<4;j++)
 			printf("%d %d %d\n",i,j,omp_get_thread_num());
}

