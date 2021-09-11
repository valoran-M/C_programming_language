/**
 * Exercice 5.10:
 * 
 *  Write a programs entab and detab (written as exercises on
 * Chapter 1) to accept a list of tab stops as arguments.
 * Use the default tab set tings if ther are no argument. 
 * For example,
 * 
 *      expr 2 3 4 + *
 * 
 * evaluates 2 * ( 3 + 4)
 * 
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 15

unsigned char stack_pointer = 0;
float stack[STACK_SIZE];

float pop(void);
void push(float element);

int main(int argc, char const *argv[])
{
    float number;
    int i;
    for (i = 1; i < argc; i++)
    {
        number = atof(argv[i]);
        if (number || strcmp(argv[i], "0") == 0)
        {
            push(number);
        }
        else if (strlen(argv[i]) == 1)
        {
            float number1 = pop();
            float number2 = pop();

            char op = *argv[i];
            switch (op)
            {
            case '+':
                push(number1 + number2);
                break;

            case '-':
                push(number1 - number2);
                break;

            case '*':
                push(number1 * number2);
                break;

            case '/':
                if (number2 == 0)
                {
                    printf("Error: division by zero (NaN).\n");
                    return EXIT_FAILURE;
                }
                push(number1 / number2);
                break;

            default:
                printf("Error: invalid operation. use one of the following mathematical operations: '+', '-', '*', '/'.\n");
                return EXIT_FAILURE;
                break;
            }
        }
    }
    printf("result: %.2f\n", pop());
    return 0;
}

float pop(void)
{
    if (stack_pointer > 0)
    {
        return stack[stack_pointer--];
    }

    printf("Error: the stack is empty.\n");
    return 0;
}

void push(float element)
{
    if (stack_pointer < STACK_SIZE)
    {
        stack[++stack_pointer] = element;
    }
    else
    {
        printf("Error: the stack is full.\n");
    }
}