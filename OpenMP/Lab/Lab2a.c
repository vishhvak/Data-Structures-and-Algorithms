#include<omp.h>
#include<stdio.h>
int main()
{
    int a[1000];
    for(int i=0;i<1000;i++)
        a[i]=i;
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        #pragma omp for
        for(int i=0;i<1000;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\nInside Thread %d",omp_get_thread_num());
        printf("\nTotal No. of Threads = %d",omp_get_num_threads());
    }   
    return 0;
}
