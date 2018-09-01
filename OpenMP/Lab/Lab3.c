#include<omp.h>
#include<stdio.h>
int main()
{
    int a[100],b[100],c[100];
    for(int i = 0; i < 100; i++)
    {
        a[i] = 7;
        b[i] = 5;
    }
    #pragma omp parallel num_threads(2)
    {
        #pragma omp single
        {
            printf("\nInside Thread %d for addition : Result - ",omp_get_thread_num());
            for(int i=0;i<100;i++)
            {
                c[i]=a[i]+b[i];
                printf("%d ",c[i]);
            }
            printf("\n");
        }
        #pragma omp single
        {
            printf("\nInside Thread %d for addition : Result - ",omp_get_thread_num());
            for(int i=0;i<100;i++)
            {
                c[i]=a[i]-b[i];
                printf("%d ",c[i]);
            } 
        }
    }        
    return 0;
}