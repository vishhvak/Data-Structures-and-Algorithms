#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	#pragma omp parallel sections num_threads(2)
		#pragma section 
		{
			printf("Hello from Section 1, Thread %d\n",omp_get_thread_num());
		}
		#pragma section 
		{
			printf("Welcome to Section 2, Thread %d\n",omp_get_thread_num());
		}
	return 0;
}
	
			
