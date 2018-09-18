#include<stdio.h>
#include<pthread.h>

int a[100];
void *prime1()
{
for(int i=0;i<100;i++)
	if(a[i]!=0)
		for(int j=i+1;j<100;j++)
			if(a[j]!=0)
				if(a[j]%a[i]==0)
					a[j]=0;	
					
for(int i=0;i<100;i++)
		if(a[i]!=0)
			printf("%d\t",a[i]);	
}
int main()
{
	for(int i=2;i<103;i++)
		a[i-2]=i;
	pthread_t t1,t2;
	pthread_create(&t1,NULL,prime1,NULL);
	pthread_join(t1,NULL);			
	printf("\n");
}