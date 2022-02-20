#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polish.h"
#include "stack.h"
#include <math.h>
#include <ctype.h>

void evaluate(char input[], stack *myStack)
{
    char *op = strtok(input, " "); // a space needs to be added at the end of expression
    int isWorking = 1;
    while (op != NULL)
    {
        if (isdigit(*op) || *op == '.')
        {
            double operand = atof(op); // come back and handle atof fail
            push(myStack, operand);
        }
        else if (strlen(op) == 1)
        {
            // if (willWork(myStack))
            // {
            double opOne = 0;
            double opTwo = 0;

            switch (*op)
            {
            case '+':
                if (willWork(myStack))
                {
                    push(myStack, (pop(myStack) + pop(myStack)));
                }
                // printf("= %f ",(pop(myStack) + pop(myStack)) )
                break;
            case '-':
                push(myStack, (pop(myStack) - pop(myStack)));
                break;

            case '/':
                opOne = pop(myStack);
                opTwo = pop(myStack);
                if (opTwo != 0)
                {
                    push(myStack, (opOne / opTwo));
                }
                else
                {
                    printf("divide by zero error\n");
                    isWorking = 0;
                }
                break;

            case '*':
                push(myStack, (pop(myStack) * pop(myStack)));
                break;

            default:
                printf("unrecognized input error '%s'\n", op);
                isWorking = 0;
                break;
            }
            //}
            // else
            // {
            //     printf("insuffcient operands error\n");
            //     isWorking = 0;
            // }
        }
        else
        {
            printf("'%s' \n", op);
            printf("wrong input error\n");
            isWorking = 0;
        }

        op = strtok(NULL, " ");
    }
    if (myStack->stackSize > 1)
    {
        isWorking = 0;
        printf("too many operands error\n");
    }

    if (isWorking)
    {
        printf("%f\n", pop(myStack));
    }

    else
    {
        // redo
    }
}

int willWork(stack *myStack)
{
    printf("stack's size is %d\n", myStack->stackSize);
    if (myStack->stackSize > 1)
    {
        return 1;
    }
    else
    {
        printf("insuffcient operands error\n");
        return 0;
    }
}