#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[100],i,j;
	for(i=1;i<=100;i++)
		a[i]=i;
	for(i=2;i<=100;i++)
		for(j=i+1;j<=100;j++)
			if(a[j]%i==0)
				a[j]=0;
	for(i=2;i<=100;i++)
		if(a[i]!=0)
			printf("%d ",a[i]);
	return 0;
}