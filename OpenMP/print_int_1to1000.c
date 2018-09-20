//Printing integers from 1 to 10000 using omp parallel for
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int i, n = 10001;
	#pragma omp parallel for
	for(i = 1; i < n; i++) {
		printf("%d\n",i);
	}
}

/*Sequential -
real	0m0.020s
user	0m0.001s
sys		0m0.019s

OpenMP
real	0m0.036s
user	0m0.043s
sys		0m0.039s

Sequential programming is faster here becase of the extra context switching time spent by OS for moving across threads. 
If the size is small, go for sequential programming. Parallel programming will be suitable when there is no data dependency 
and a large amount of data to handle.

*/

