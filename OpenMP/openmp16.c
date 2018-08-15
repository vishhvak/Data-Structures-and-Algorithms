#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int ReadWords(const char *filename, char *words[], int max_number_of_words)
{
    FILE *f = fopen(filename, "rt"); 
    int i;
    char temp[100];
    for (i = 0; i < max_number_of_words; ++i)
    {
        if (fscanf(f, "%s", temp) != 1)
            break;
        words[i] = strdup(temp);
    }
    fclose(f);
    return i;
}
int main()
{
	char *words[100];
	char *word1[100];
	char *word2[100];
	char s[] = "abc";
	int num = ReadWords("a.txt",words,20);
	int nums,i,j, k=0,count=0,total=0;
	printf("\nNumber of words in text file is %d\n",num);
	for(i=0;i<num;i++)
		word1[i] = strdup(words[i]);
    for(i=0;i<num;i++)
    	for(j=i+1;j<num;j++)
    		if(strcmp(word1[i],words[j])==0)	
    			words[j]=strdup(s);
    for(i=0;i<num;i++)
    	if(strcmp(words[i],s)!=0)
    		word2[k++]=words[i];
    nums = k;
    #pragma omp parallel for reduction(+:total)
    for(i=0;i<nums;i++)
    {
    	count = 0;
    	for(j=0;j<num;j++)
    	{
    		if(strcmp(word2[i],word1[j])==0)
    		{
    			++count;
    			if(count>2)
    				total=total+1;
    		}
    	}
    }
    printf("\nThe number of words occuring more than twice is %d",total);
    return 0;
}