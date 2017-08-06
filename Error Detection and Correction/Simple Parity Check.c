//
//  Simple Parity Check.c
//  Error Detection and Correction
//
//  Created by Vishhvak Srinivasan on 26/04/17.
//  Copyright © 2017 Vishhvak Srinivasan. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long t_get()
{
    long data;
    printf("Enter the data to be transmitted");
    scanf("%ld",&data);
    return data;
}
long r_get()
{
    long data;
    printf("Enter the data recieved");
    scanf("%ld",&data);
    return data;
}

int count1(long data)
{
    long temp;
    temp=data;
    int count=0;
    while(temp>0)
    {
        int c;
        c=temp%10;
        temp=temp/10;
        if(c==1)
            count++;
        
    }
    return count;
}

long add_parity(long t_data,int i)
{
    long temp;
    temp=t_data;
    int c;
    c=count1(t_data);
    if(i==1)
    {
        if(c%2!=0)
            t_data*=10;
        else
        {
            t_data*=10;
            t_data+=1;
        }
    }
    else if(i==2)
    {
        if(c%2==0)
            t_data*=10;
        else
        {
            t_data*=10;
            t_data+=1;
        }

    }
    printf("\nData transmitted after adding parity bit - %ld\n",t_data);
    return t_data;
}

void check_parity(long data1,long data2)
{
    int c1,c2;
    c1=count1(data1);
    c2=count1(data2);
    if(c1==c2)
        printf("\nNo Error in Transmission\n");
    else
        printf("\nError in Transmission\n");
}

int main()
{
    long t_data, r_data;
    t_data=t_get();
    char ch;
    printf("\nChoose Parity\n");
    printf("1.Odd Parity\n");
    printf("2.Even Parity\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1':
            t_data=add_parity(t_data,1);
            r_data=r_get();
            check_parity(t_data,r_data);
            break;
        case '2':
            t_data=add_parity(t_data,2);
            r_data=r_get();
            check_parity(t_data,r_data);
            break;
        default:
            printf("\nWrong Choice, Aborting\n");
            exit(0);
    }
}
