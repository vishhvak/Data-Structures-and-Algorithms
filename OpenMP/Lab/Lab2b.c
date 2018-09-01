#include<omp.h>
#include<stdio.h>
int main()
{
    int a[1000];
    for(int i=0;i<1000;i++)
        a[i]=i;
    #pragma omp parallel
    {
    	#pragma omp for
    	for(int i=0;i<1000;i++)
        	printf("%d ",a[i]);
        printf("\nThread number = %d\n",omp_get_thread_num());
	}
    return 0;
}
