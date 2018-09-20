#include<stdio.h>
#include<omp.h>

int main()
{
	int m,n,p,q;
	int sum;
	int a[10][10],b[10][10],mm[10][10];
	printf("Enter the size of matrix A: ");
	scanf("%d%d",&m,&n);
	printf("Enter the size of matrix B: ");
	scanf("%d%d",&p,&q);
	if(n!=p)
		printf("Matrix multiplication not possible");
	else
	{
		printf("Enter the elements of matrix A: ");
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		
		printf("Enter the elements of matrix B: ");
		for(int i=0;i<p;i++)
			for(int j=0;j<q;j++)
				scanf("%d",&b[i][j]);

		#pragma omp parallel for //For the 1st, 2nd and 3rd case
		for(int i=0;i<m;i++)
		    #pragma omp parallel for reduction(+: sum) //For the 2nd and 3rd case
			for(int j=0;j<q;j++)
				{
				sum=0;
				#pragma omp parallel for //For the 3rd case
				for(int k=0;k<n;k++)
					sum+=(a[i][k]*b[k][j]);
				mm[i][j]=sum;
				}
		
		printf("The resultant matrix is: \n");
		for(int i=0;i<m;i++)
			{
			for(int j=0;j<q;j++)
				printf("%d\t",mm[i][j]);
			printf("\n");
			}
	}
}