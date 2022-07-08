// Deterministic Finite Automaton (DFA) implementation in C-language 

// Author: Nikhil Singh
// Last Modified: 08/07/2022


#include <stdbool.h>
#include <stdio.h>
#include <string.h>


struct FiniteAutomata {

    char inpSymbol[10];
    int NOS;
    int NOF;
    int NOI;
    int final[10];
    int delta[10][10];
};


int lookForSymbol(struct FiniteAutomata fa, char ch) {

    for (int i = 0; i < fa.NOI; ++i) {
        if (ch == fa.inpSymbol[i]) { return i; }
    }
    return -1;
}


int lookFinalStates(struct FiniteAutomata fa, int state) {

    for (int i = 0; i < fa.NOF; ++i) {
        if (state == fa.final[i]) {
            return 1;
        }
    }

    return 0;
}


int main(void) {
    
    struct FiniteAutomata fa = {0};
    printf("\nEnter number of total states: ");
    scanf("%d", &fa.NOS);
    printf("Enter number of final states: ");
    scanf("%d", &fa.NOF);
    printf("Enter number of input symbol: ");
    scanf("%d", &fa.NOI);

    printf("\n");

    for (int i = 0; i < fa.NOI; ++i) {

        fflush(stdin); 
        printf("Enter input symbol number[%d]: ", (i + 1));
        fflush(stdin); 
        scanf("%c", &fa.inpSymbol[i]);
        printf("\n");
    }

    for (int i = 0; i < fa.NOF; i++) {
        printf("Enter final states number[%d]: ", (i + 1));
        scanf("%d", &fa.final[i]);
    }

    printf("\nEnter Formal Automaton Transitions:\n\n");

    for (int i = 0; i < fa.NOS; i++) {

        for (int j = 0; j < fa.NOI; j++) {
            printf("d(Q%d, %c) : ", i, fa.inpSymbol[j]);
            scanf("%d", &fa.delta[i][j]);
        }
    }

    
    for (int i = 0; i < fa.NOI; i++) {
        printf("\t%c", fa.inpSymbol[i]);
    }


    printf("\n");

    for(int i = 0; i < fa.NOS; i++) {

        printf("\nQ%d", i);  
        for(int j = 0; j < fa.NOI; j++) {
            printf("\t%d", fa.delta[i][j]);
        }
        printf("\n");
    }

    do {

        char string[10]; int flag = 1;
        printf("\nInput the test-string: ");
        scanf("%s", string);
        int stateCounter = 0;
        
        for(int i = 0; i < strlen(string); i++) {
    
            int symPos = lookForSymbol(fa, string[i]);
            
            if(symPos == -1) {
                flag = 0;
                break;
            }
            stateCounter = fa.delta[stateCounter][symPos];
        }

        if (flag == 1 && lookFinalStates(fa, stateCounter) == 1) {
            printf("String[%s] is accepted.", string);
        }

        else { printf("String[%s] is rejected.", string); }

    } while(true);

    return 0;
}
