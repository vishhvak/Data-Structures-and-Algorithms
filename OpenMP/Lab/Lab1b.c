#include<pthread.h>
#include<stdio.h>
void * f1(char *s)
{
	int i,c=0;
	for(i=0;s[i]!='\0';i++)
		if( (s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u') ) 
			c++;
	printf("Vowels : %d",c);
	return NULL;
}

void * f2(char *s)
{
	int i,c=0;
	for(i=0;s[i]!='\0';i++)
		if(!( (s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u') ) ) 
			c++;
	printf("Consonants : %d",c);
	return NULL;
}

pthread_t p1,p2;
 
int main()
{
	char s[10];
	int i=0;
	FILE *fp;
	fp=fopen("a.txt","r"); 
	while(!feof(fp))
	{     
		s[i]=fgetchar(fp);    
		i++; 
	} 
	pthread_create(&p1,NULL,f1,&s); 
	pthread_join(p1, NULL); 
	pthread_create(&p2,NULL,f2,&s); 
	pthread_join(p2, NULL); 
	return 0; 
}

