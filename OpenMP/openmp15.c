#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[100000];
    omp_set_num_threads(2);
    int m=0;
    int i;
    for( i=0; i<100000; i++)
        arr[i] = 2 + i;
    #pragma omp parallel for reduction(max : m)
    for( i=0;i<100000; i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];  
        }
    }  
    printf("\nMax_val = %d", m);
    return 0;
}