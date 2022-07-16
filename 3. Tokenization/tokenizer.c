/*  Implementing tokenizer (divides the input stream into individual tokens, identifies the token-type, and passes tokens one at 
    a time to the parser) in C-language
*/

// Author: Nikhil Singh
// Last Modified: 08/07/2022


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(void) {

    FILE *insert, *output;
    int idx = 0, flag = 0;
    char ch, lexeme[20];
    int line = 1, token = 0;
    
    insert = fopen("insert.txt", "r");
    output = fopen("output.txt", "w");
    
    char keyword[32][32] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", 
                             "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
                             "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

    fprintf(output, "Line Number\tToken Number\tToken Types\t\t Lexeme\n\n");

    while (!feof(insert)) {

        idx = 0; flag = 0;
        ch = fgetc(insert);

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {

            fprintf(output,"%6d\t\t %6d\t\t Operator\t\t %11c\n", line, token, ch);
            token++;
        }

        else if (ch == ';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' ||
                 ch == '@' || ch=='!' || ch=='%') {

            fprintf(output,"%6d\t\t %6d\t\t Special Symbol\t %6c\n", line, token, ch);
            token++;
        }

        else if (isdigit(ch)) {

            fprintf(output,"%6d\t\t %6d\t\t Digit\t\t %11c\n", line, token, ch);
            token++;
        }

        else if (isalpha(ch)) {

            lexeme[idx] = ch;
            idx++;
            ch = fgetc(insert);

            while (isalnum(ch) && ch != ' ') {

                lexeme[idx] = ch;
                idx++;
                ch = fgetc(insert);
            }

            lexeme[idx] = '\0';

            for (int j = 0; j < 32; j++) {

                if (strcmp(lexeme, keyword[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {

                fprintf(output, "%6d\t\t %6d\t\t Keyword\t\t %11s\n", line, token, lexeme);
                token++;
            }

            else {

                fprintf(output, "%6d\t\t %6d\t\t Identifier\t\t %6s\n", line, token, lexeme);
                token++;
            }
        }

        else if (ch == '\n') { line++; }
    }

    fclose(insert);
    fclose(output);
  
    return 0;
}
