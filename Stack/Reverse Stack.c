//
//  Reverse Stack.c
//  DSA - Jeremy
//
//  Created by Vishhvak Srinivasan on 05/08/17.
//  Copyright © 2017 Vishhvak Srinivasan. All rights reserved.
//

#include<stdio.h>
void reverse(int [],int [],int [],int *,int *,int *);
void display(int [],int);
void input(int [],int *,int);
void main()
{
    int total;
    int stack1[100],stack2[100],stack3[100];
    int top_1=-1,top_2=-1,top_3=-1;
    printf("Enter size of stack::");
    scanf("%d",&total);
    input(stack1,&top_1,total);
    display(stack1,top_1);
    reverse(stack1,stack2,stack3,&top_1,&top_2,&top_3);
    printf("\nAfter reverse..............");
    display(stack1,top_1);
}
void input(int stack[],int *top,int size)
{
    int i,item;
    for(i=0;i<size;i++)
    {
        *top=*top+1;
        printf("Enter value of for Index %d ::",*top);
        scanf("%d",&item);
        stack[*top]=item;
    }
}
void reverse(int stack1[],int stack2[],int stack3[],int *t1,int *t2,int *t3)
{
    while(*t1>-1)
    {
        *t2=*t2+1;
        stack2[*t2]=stack1[*t1];
        *t1=*t1-1;
    }
    while(*t2>-1)
    {
        *t3=*t3+1;
        stack3[*t3]=stack2[*t2];
        *t2=*t2-1;
    }
    while(*t3>-1)
    {
        *t1=*t1+1;
        stack1[*t1]=stack3[*t3];
        *t3=*t3-1;
    }
}
void display(int stack[],int top)
{
    while(top>-1)
    {
        printf("\nValue at Index %d is %d",top,stack[top]);
        top=top-1;
    }
}
