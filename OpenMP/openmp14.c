//Using Reduction
#include<stdio.h>
#include<omp.h>
#pragma omp_set_nested(true)

int x[1000],y[1000];

int main()
{
	int i;
	for(i=0;i<1000;i++)
	{
		x[i]=1;	
		y[i]=1;
	}
	#pragma omp parallel sections
	{
		#pragma omp section
		{	
			int sum1=0;
			#pragma omp parallel for reduction(+:sum1)
				for(i=0;i<1000;i++)
					sum1+=x[i];
				printf("Thread 1: %d\n",sum1);
		}
		#pragma omp section
		{	
			int sum2=0;
			#pragma omp parallel for reduction(+:sum2)
				for(i=0;i<1000;i++)
					sum2+=y[i];
				printf("Thread 2: %d\n",sum2);
		}
		
	}	
	return 1;
}
