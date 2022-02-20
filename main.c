/*
 ============================================================================
 Name        : PolishSol.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	// char eqn[MAX_EQ_LEN];  // string to store the input RPN expression
	// schar resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"

	// stackNode *hi = NULL;
	//  stackNode *sec = NULL;
	stack myStack;
	myStack.root = NULL;
	myStack.stackSize = 0;

	printf("prompt\n");
	char input[100];
	fgets(input, 100, stdin);
	evaluate(input, &myStack);

	// push(&myStack, 5);
	// printf("there are %d items in stack\n", size(&myStack));
	// push(&myStack, 20);
	// printf("there are %d items in stack\n", size(&myStack));
	// pop(&myStack);
	// printf("there are %d items in stack\n", size(&myStack));
	// pop(&myStack);
	// printf("there are %d items in stack\n", size(&myStack));
	printf("Exiting...\n");
	return 0;
}
