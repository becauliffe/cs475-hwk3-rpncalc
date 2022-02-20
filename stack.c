#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

void push(stack *myStack, double val)
{
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->num = val;
    newNode->below = myStack->root;
    myStack->root = newNode;
    // printf("%f \n", newNode->num);
    myStack->stackSize++;
}

double pop(stack *myStack)
{
    if (myStack->root == NULL)
    {
        printf("error");
        return 0;
    }
    else
    {
        stackNode *temp = myStack->root;
        double popVal = temp->num;
        myStack->root = temp->below;
        myStack->stackSize--;
        free(temp);
        // printf("popped: %lf\n", popVal);
        return popVal;
    }
}

int size(stack *myStack)
{
    return myStack->stackSize;
}