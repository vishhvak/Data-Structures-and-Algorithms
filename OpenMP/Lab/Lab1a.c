#include<pthread.h>
#include<stdio.h>

void * t1(void *a)
{
	int i;
	for(i=1;i<500;i++) //Printing 1 to 500
		printf("%d\t",i);
	return NULL;
}

void * t2(void *a)
{
	int j;
	for(j=501;j<1000;j++) //Printing 500 to 1000
		printf("%d\t",j);
	return NULL;
}

pthread_t p1,p2;

int main()
{
	pthread_create(&p1,NULL,t1,NULL);
	pthread_join(p1, NULL);
	pthread_create(&p2,NULL,t2,NULL);
	pthread_join(p2, NULL);
	return 0;
}
