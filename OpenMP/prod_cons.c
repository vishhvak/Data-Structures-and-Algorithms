#include <omp.h>
#include <stdio.h>

int main()
{
  int a[15], i;
  for(i=0;i<15;i++) {
    a[i] = 2*i;
  }
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp critical
      for(i=0;i<15;i++)
      {
        a[i]=40-i;
        printf("Produced %d\n",a[i]);
      }
    }
    #pragma omp section
    {
      #pragma omp critical
      for(i=0;i<15;i++)
      {
        if(a[i]==0)
          printf("Empty Queue\n");
        else
          printf("Consumed %d\n",a[i]);
          a[i] = 0;
      }
    }
  }
  return 0;
}
