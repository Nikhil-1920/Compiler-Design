// Pushdown Automaton (PDA) implemented in C-language for the language {a^nb^n | n >= 1}

// Author: Nikhil Singh
// Last Modified: 08/07/2022


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack {

    int stackTop;
    int *items;
    int maxSized;
};


// A utility function to create and initialize stack
struct Stack *newStack(int capacity) {

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->maxSized = capacity;
    stack->stackTop = -1;
    stack->items = (int *)malloc(sizeof(int) * capacity);
    return stack;
}


// A utility function to check if the stack is empty
int isStackEmpty(struct Stack *stack) { return stack->stackTop == -1; }


// A utility function to check if the stack is full
int isStackFull(struct Stack *stack) { return stack->stackTop == stack->maxSized - 1; }


// A utility function to add an element to the stack
void push(struct Stack *stack, int data) {

    if (isStackFull(stack)) { exit(EXIT_FAILURE); }
    stack->items[++stack->stackTop] = data;
}


// A utility function to pop a top element from the stack
int pop(struct Stack *stack) {

    if (isStackEmpty(stack)) { exit(EXIT_FAILURE); }
    return stack->items[stack->stackTop--];
}


int main(void) {

    char str[10] = {0};
    printf("\nProgram to create PDA which accpets langauge {(a^n)(b^n) : n >= 1}\n");
    printf("\nEnter the string: ");
    scanf("%s", str);
    int n = strlen(str);
    
    struct Stack *st = newStack(n);
    st->stackTop = -1;

    for (int i = 0; i < n; i++) {

        if (str[i] == 'a' || str[i] == 'b') {
            
            if (str[i] == 'a') { push(st, str[i]); }
            else { pop(st); }   
        }
        
        else { goto exit; }    
    }

    if (st->stackTop == -1) { 
        printf("String Accepted.\n\n");
    }

    else { 
        exit:
        printf("String Rejected.\n\n"); 
    } 

    return 0;
}
