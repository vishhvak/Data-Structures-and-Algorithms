#include <stdio.h>
#include<stdlib.h>
#define maxlength 10
#define maxmessages 10

void initialize(int arr[][10],int m,int n)

{
    
    for(int i =0;i<m;i++)
        
        for(int j=0;j<n;j++)
            
        {
            
            arr[i][j] = rand()%2;
            
        }
    
}

void print(int arr[][10],int m,int n)

{
    
    for(int i =0;i<m;i++)
        
    {  for(int j=0;j<n;j++)
        
    {
        
        printf("%d ",arr[i][j]);
        
    }
        
        printf("\n");
        
    }
    
}

void addparbit(int arr[][10],int m,int n)  // Even Parity

{
    
    for(int i=0;i<m;i++)
        
    {
        
        int count = 0;
        
        for(int j=0;j<n;j++)
            
        {
            
            if(arr[i][j] == 1)
                
                count++;
            
        }
        
        if(count%2 == 0)
            
            arr[i][n] = 0;
        
        else
            
            arr[i][n] = 1;
        
    }
    
    for(int i=0;i<n;i++)
        
    {
        
        int count = 0;
        
        for(int j=0;j<m;j++)
            
        {
            
            if(arr[j][i] == 1)
                
                count++;
            
        }
        
        if(count%2 == 0)
            
            arr[m][i] = 0;
        
        else
            
            arr[m][i] = 1;
        
    }
    
}

void induceerror(int arr[][10],int m,int n)

{
    
    int k1,k2;
    
    k1= rand()%m;
    
    k2 = rand()%n;
    
    if(arr[k1][k2]==0)
        
        arr[k1][k2]=1;
    
    else
        
        arr[k1][k2]=0;
    
    printf("Inducing error at line : %d,%d",k1,k2);
    printf("\n");
}

void checkerror(int arr[][10],int m,int n)

{
    
    printf("Error at:");
    for(int i=0;i<m;i++)
        
    {
        
        int count = 0;
        
        for(int j=0;j<n;j++)
            
        {
            
            if(arr[i][j] == 1)
                
                count++;
            
        }
        
        if(count%2 == 0 && arr[i][n] != 0)
            
        {
            
            printf("\nRow : %d\n",i);
            
        }
        
        else if(count%2 == 1 && arr[i][n] != 1)
            
        {
            
            printf("\nRow : %d\n",i);
            
        }
        
    }
    
    for(int i=0;i<n;i++)
        
    {
        
        int count = 0;
        
        for(int j=0;j<m;j++)
            
        {
            
            if(arr[j][i] == 1)
                
                count++;
            
        }
        
        if(count%2 == 0 && arr[m][i] != 0)
            
        {
            
            printf("Column : %d\n",i);
            
        }
        
        else if(count%2 == 1 && arr[m][i] != 1)
            
        {
            
            printf("Column : %d\n",i);
            
        }
        
    }
    
}



int main()

{   int m,n,arr[maxmessages][maxlength];
    
    printf("Enter total number of messages");
    
    scanf("%d",&m);
    
    printf("Enter length of each message");
    
    scanf("%d",&n);
    
    initialize(arr,m,n);
    
    printf("\n");
    
    print(arr,m,n);
    
    printf("\n");

    
    addparbit(arr,m,n);
    
    printf("\n2-D Parity Matrix after adding Parity Bits to Rows and Columns\n");
    
    
    print(arr,m+1,n+1);
    
    printf("\n");

    
    induceerror(arr,m,n);
    
    print(arr,m+1,n+1);
    
    printf("\n");

    
    checkerror(arr,m,n);
    printf("\n");
    
    return 0;
    
}

