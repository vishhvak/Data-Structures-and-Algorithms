#include<stdio.h>
#include<omp.h>
int main()
{
	int m=100,n=100,p=100,q=100;
	int sum=0;
	int a[500][500],b[500][500],mm[500][500];
	if(n!=p)
		printf("Matrix multiplication not possible");
	else
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				a[i][j]=i+j;
		for(int i=0;i<p;i++)
			for(int j=0;j<q;j++)
				b[i][j]=i-j;
		#pragma omp parallel for collapse(2)
		for(int i=0;i<m;i++)
			for(int j=0;j<q;j++)
			{
				for(int k=0;k<n;k++)
					sum+=(a[i][k]*b[k][j]);
				mm[i][j]=sum;
				sum=0;
			}
	}
}
