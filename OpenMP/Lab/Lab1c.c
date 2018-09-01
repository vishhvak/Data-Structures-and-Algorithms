#include<pthread.h>
#include<stdio.h>

void * f1(void *x)
{
	int a[100][100],b[100][100];
	int i,j,c[100][100];
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			a[i][j]=j;
			b[i][j]=j*3;
		}
	}
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d\t",c[i][j]);
		}
	printf("\n");
	}
	return NULL;
}

void * f2(void *x)
{
	int a[100][100],b[100][100];
	int i,j,d[100][100];
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			a[i][j]=j;
			b[i][j]=j*3;
		}	
	}
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			d[i][j]=a[i][j]-b[i][j];
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	return NULL;
}

pthread_t p1,p2;

int main()
{
	pthread_create(&p1,NULL,f1,NULL);
	pthread_join(p1, NULL);
	pthread_create(&p2,NULL,f2,NULL);
	pthread_join(p2, NULL);
	return 0;
}
