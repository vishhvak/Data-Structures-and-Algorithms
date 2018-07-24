#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int nthreads, tid, nproc;
	nproc = omp_get_num_procs();
	printf("Number of CPUs is %d\n",nproc);
	#pragma omp parallel private(nthreads, tid) {
		tid = omp_get_thread_num();
 		printf("Thread ID = %d\n", tid);
 		if (tid == 0) 
 		{
  			nthreads = omp_get_num_threads();
 			printf("Total Thread Count = %d\n", nthreads);
 		}
	}
}

