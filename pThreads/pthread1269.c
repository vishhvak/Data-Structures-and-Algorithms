#include<stdio.h>
#include<pthread.h>
 
void* p1prime(void* data1)
{
    int num, d;
    printf("\nThread 1 Function starting\n");
    for (num = 1; num <= 500; num++)
    {
      for(d = 2; d < num; d++)
      {
        if (num % d == 0)
           break;
      }
      if (d == num)
        printf("%d ", num);
    }
    printf("\nThread 1 Function done.");
    printf("\n");
}

void* p2prime(void* data)
{
    printf("\nThread 2 Function starting\n");
    int num,d; 
    for (num = 501; num <= 1000; num++)
    {
      for(d = 2; d < num; d++)
      {
        if (num % d == 0)
           break;
      }
      if (d == num)
        printf("%d ", num);
    }
    printf("\nThread 2 Function done.");
    printf("\n");
}

void main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL, p1prime, "hello");
    pthread_join(t1,NULL);
    pthread_create(&t2,NULL, p2prime, "hello");
    pthread_join(t2,NULL);

}


