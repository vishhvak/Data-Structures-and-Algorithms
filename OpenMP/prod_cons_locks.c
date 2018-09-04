#include <omp.h>
#include <stdio.h>
int main()
{
  int a[15], i;
  omp_lock_t l;
  omp_init_lock(&l);
  #pragma omp parallel sections
  {
  	#pragma omp section
    {
    	omp_set_lock(&l);
    	for(i=0;i<15;i++)
    	{
    		a[i]=i+1;
        	printf("Produced %d\n",a[i]);
        }
        omp_unset_lock(&l);
    }
    #pragma omp section
    {
    	omp_set_lock(&l);
    	for(i=0;i<15;i++)
      	{
        	if(a[i]==0)
          	printf("Empty Queue\n");
        	else
          	printf("Consumed %d\n",a[i]);
          	a[i] = 0;
       	}
       	omp_unset_lock(&l);
    }
  }
  return 0;
}