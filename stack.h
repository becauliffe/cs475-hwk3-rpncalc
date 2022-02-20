/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct stackNode
{
    double num;
    struct stackNode *below;
} stackNode;

typedef struct Stack
{
    stackNode *root;
    int stackSize;
} stack;

void push(stack *myStack, double val);
double pop(stack *myStack);
int size(stack *myStack);
#endif /* STACK_H_ */
