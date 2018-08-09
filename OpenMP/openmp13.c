//Count vowels and consonants, from a text file's contents
// x.txt = This is to count the number of vowels and consonants.
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#pragma omp_set_nested(true)

int main()
{
	int i;
	char x[500];
	char y[100];
	FILE *file;
	file=fopen("x.txt","r");
	while(fgets(y, 100, (FILE*)file))
		strcat(x,y);
	int len=strlen(x);
	fclose(file);
	#pragma omp parallel sections
	{
		#pragma omp section
		{	
			int count=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<len;i++)
					if(isalpha(x[i]))
						if(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u' || x[i]=='A' || x[i]=='E' || x[i]=='I' || x[i]=='O' || x[i]=='U')
							count+=1;
				printf("Vowels: %d\n",count);
		}
		#pragma omp section
		{	
			int count=0;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<len;i++)
					if(isalpha(x[i]))
						if(!(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u' || x[i]=='A' || x[i]=='E' || x[i]=='I' || x[i]=='O' || x[i]=='U'))
						count+=1;
				printf("Consonants: %d\n",count);
		}
		
	}	
	return 1;
}
