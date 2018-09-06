#include <stdio.h>
#include <unistd.h>
int power(int d,int n)
{
	int p=1;
	for(int i=0;i<n;i++)
		p*=d;
	return p;
}

int main()
{
    if(fork()==0)
    {
    	printf("Prime numbers between 0 to 100\n\n");
        int a[200],c=0;
    
        for(int i=0;i<101;i++)
            a[i]=i;
    
        for(int i=2;i<101;i++)
            for(int j=i+1;j<101;j++)
                if(a[i]!=0)
                    if(a[j]%a[i]==0)
                    {
                        a[j]=0;
                        continue;
                    } 
    
        for(int i=0;i<101;i++)
            if(a[i]!=0)
                printf("%d ", a[i]);
    printf("\n");
    }
    else if(fork()==0)
    {
    	printf("\nArmstrong numbers between 0 to 1000\n\n");
        int number, temp, digit1, digit2, digit3;
   		number = 001;
   		while (number <= 900)
   		{
   		    digit1 = number - ((number / 10) * 10);
   		    digit2 = (number / 10) - ((number / 100) * 10);
   		    digit3 = (number / 100) - ((number / 1000) * 10);
   		    temp = (digit1 * digit1 * digit1) + (digit2 * digit2 * digit2) + (digit3 * digit3 * digit3);
   		    if (temp == number)
   		    {
   		        printf("%d\t", temp);
   		    }
   		number++;
    	}
    }
	printf("\n\n");
    return 0;
}