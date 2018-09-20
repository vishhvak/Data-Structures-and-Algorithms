#include<stdio.h>
#include<omp.h>

int main()
{
int a[100];
for(int i=2;i<103;i++)
	a[i-2]=i;

for(int i=0;i<100;i++)
	if(a[i]!=0)
		#pragma omp parallel for
		for(int j=i+1;j<100;j++)
			if(a[j]!=0)
				if(a[j]%a[i]==0)
					a[j]=0;
				
for(int i=0;i<100;i++)
	if(a[i]!=0)
		printf("%d\t",a[i]);
printf("\n");
}

