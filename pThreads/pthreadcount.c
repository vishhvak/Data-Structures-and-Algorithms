#include<stdio.h>
#include<pthread.h>
#include<string.h>
int count = 0;
void* vowels(void* data)
{
   int l;
   char* string;
   string = data;
   l = strlen(string);
   for (int i = 0; i < l; i++ )
   {
     if(string[i] == 'a' || string[i] == 'e' || string[i] == 'o' || string[i] == 'i' || string[i] == 'u')
   	count++;
   }
   printf("Number of vowels is %d\n", count);
   return NULL;
}

void* consonants(void* data)
{
    int l, conso;
    char* string;
    string = data;
    l = strlen(string);
    conso = l - count;
    printf("Number of consonants is %d\n", conso);
    return NULL;
}

int main()
{
    FILE * fp; 
    char str1[10];
    fp = fopen("16bce1269.txt", "r");
    fscanf(fp, "%s", str1);
    printf ("The word in the file is - %s\n", str1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL, vowels, &str1);
    pthread_join(t1,NULL);
    pthread_create(&t2,NULL, consonants, &str1);
    pthread_join(t2,NULL);
    return 0;
}


