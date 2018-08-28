#include <omp.h>
#include <stdio.h>

int main()
{
  int a[50], i;
  for(i=0;i<50;i++) {
    a[i] = i;
  }
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      #pragma omp critical
      for(i=0;i<20;i++)
      {
        a[i]=50-i;
        printf("Produced %d\n",a[i]);
      }
    }
    #pragma omp section
    {
      #pragma omp critical
      for(i=0;i<20;i++)
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
