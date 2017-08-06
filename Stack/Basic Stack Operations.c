//
//  main.c
//  DSA - Jeremy
//
//  Created by Vishhvak Srinivasan on 05/08/17.
//  Copyright © 2017 Vishhvak Srinivasan. All rights reserved.
//
//stack using array
#include<stdio.h>
void push();
void pop();
void display();
int n;
void main()
{
    int stack[100],n,top,i;
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\tEnter the elements of the stack");
    int i;
    for(i=0;i<n;i++)
        push(stack,top);
}
void push(int stack[],int &top)
{
    int x;
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        getch();
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(int &top)
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        top--;
    }
}

void display(int &top)
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(int i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
        printf("\n The STACK is empty");
}

void sort(int stack[], int &top)
{
    int tempstack[100],top1,j,temp;
    while(top!==-1)
    {
        temp=stack[top];
        pop(top);
        
    }
}
