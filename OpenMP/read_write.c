#include <stdio.h>
#include <omp.h>
#include <unistd.h>
int main() {
	int reader, writer;
	printf("Enter number of readers\n");
	scanf("%d", &reader);
	omp_set_num_threads(reader);
	printf("Enter number of writers\n");
	scanf("%d", &writer);

	printf("Starting Reading\n");

	#pragma omp parallel
	{
		printf("Thread %d is entering shared region\n", omp_get_thread_num());
		printf("Thread %d is reading shared region\n", omp_get_thread_num());
		printf("Thread %d is leaving shared region\n", omp_get_thread_num());
	}

	omp_set_num_threads(writer);
	printf("Writing Begins\n");

	#pragma omp parallel 
	{
		#pragma omp critical 
		{
			printf("Thread %d is entering shared region\n", omp_get_thread_num());
			printf("Thread %d is writing/modifying the shared region\n", omp_get_thread_num());
			printf("Thread %d is leaving shared region\n", omp_get_thread_num());
		}
	}
	return 0;
}