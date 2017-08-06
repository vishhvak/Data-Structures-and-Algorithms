#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int size, int *top, int item)
{
    if(*top==size)
        printf("\nStack is full! ");
    else
    {
        *top+=1;
        stack[*top]=item;
    }
}

int pop(int stack[], int *top)
{
    if(*top<=0)
        printf("\nStack is empty! ");
    else
    {
        *top-=1;
        return stack[(*top)+1];
    }
    return 0;
}

void display(int stack[], int *top)
{
    int i;
    if(*top<=0)
        printf("\nStack is Empty!");
    for(i=1; i<=*top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void sort(int stack[], int *top, int size)
{
    int temp_stack[size],temp,top2=0;
    while (*top>0)
    {
        // pop out the first element
        temp = stack[*top];
        pop(stack,top);
        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (top2>0 && temp_stack[top2]>temp)
        {
            // pop from temporary stack and push
            // it to the input stack
            push(stack,size,top,temp_stack[top2]);
            pop(temp_stack,&top2);
        }
        // push temp in tempory of stack
        push(temp_stack,size,&top2,temp);
    }
    for(int i=0;i<size;i++)
        push(stack,size,top,pop(temp_stack,&top2));
    display(stack,top);
}

int main()
{
    int size, item;
    printf("Enter the size of your stack: ");
    scanf("%d", &size);
    int stack[size], top=0;
    printf("\nEnter the elements of the stack: ");
    while(top<size)
    {
        scanf("%d", &item);
        push(stack, size, &top, item);
    }
    printf("\nStack before sorting\n");
    display(stack,&top);
    printf("\nStack after sorting\n");
    sort(stack,&top,size);
    return 0;
}
