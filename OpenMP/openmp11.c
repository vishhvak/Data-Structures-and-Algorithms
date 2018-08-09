//Vector Addition using sections
#include<omp.h>
#pragma omp_set_nested(true)

int a[1000],b[1000];

int main()
{
	int i;
	for(i=0;i<1000;i++)
	{
		a[i]=1;	
		b[i]=1;
	}
	#pragma omp parallel sections
	{
		#pragma omp section
		{	
			int sum=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<1000;i++)
					sum+=a[i];
				printf("Thread 1: %d\n",sum);
		}
		#pragma omp section
		{	
			int sum=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<1000;i++)
					sum+=b[i];
				printf("Thread 2: %d\n",sum);
		}
		
	}	
	return 1;
}
