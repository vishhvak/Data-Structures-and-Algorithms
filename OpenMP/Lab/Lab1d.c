#include<pthread.h>
#include<stdio.h>
#include<string.h>
char a[]="vishhvak";
void * f1(void *x)
{
    int l=strlen(a);
	int i;
	for(i=l;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");
	return NULL;
}

void * f2(void *x)
{
	int i;
	int l=strlen(a);
	char b[10];
	for(i=0;i<l;i++)
	{
		b[i]=a[i]+1;
		printf("%c",b[i]);
	}
	printf("\n");
	return NULL;
}

pthread_t p1,p2;

int main()
{
    printf("Original String: %s\n",a);
	pthread_create(&p1,NULL,f1,NULL);
	pthread_join(p1, NULL);
	pthread_create(&p2,NULL,f2,NULL);
	pthread_join(p2, NULL);
	return 0;
}

