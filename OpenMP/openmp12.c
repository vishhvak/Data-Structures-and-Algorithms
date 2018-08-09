//Count vowels and consonants from a string using sections
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#pragma omp_set_nested(true)

int main()
{
	int i;
	char a[]="This is to count the number of vowels and consonants";
	int len=strlen(a);
	#pragma omp parallel sections
	{
		#pragma omp section
		{	
			int sum=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<len;i++)
					if(isalpha(a[i]))
						if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
							sum+=1;
				printf("Vowels: %d\n",sum);
		}
		#pragma omp section
		{	
			int sum=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<len;i++)
					if(isalpha(a[i]))
						if(!(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U'))
						sum+=1;
				printf("Consonants: %d\n",sum);
		}
		
	}	
	return 1;
}
