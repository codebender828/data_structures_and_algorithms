//
// Created by Jonathan Bakebwa on 29/01/2018.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char brackets;
    struct node *next;
    struct node *pre;
}NODE;

int main(int argc, char* argv[]){
    int i;
    NODE *a;
    NODE *b;
    NODE * bracket;
    char equation[50];

    //create the brackets pointers

    bracket = (NODE*)malloc(sizeof(NODE));
    bracket->brackets = '$';
    //input the equation
    scanf("%s",&equation);

    for(b = bracket, i = 0; i < strlen(equation); i++){
        if((equation[i] == '[') || (equation[i] == '{') || (equation[i]) == '('){
            a = (NODE*)malloc(sizeof(NODE));
            a->brackets = equation[i];
            b->next = a;
            a->pre = b;
            b = a;
        } else if(equation[i] == ')'){
            if(b->brackets != '('){
                printf("Match false!\n");
                goto Mismatch;
            } else {
                a = b;
                b = b->pre;
                free(a);
            }
        } else if(equation[i] == ']'){
            if(b->brackets != '['){
                printf("Match false!\n");
                goto Mismatch;
            } else {
                a = b;
                b = b->pre;
                free(a);
            }
        } else if(equation[i] == '}'){
            if(b->brackets != '{'){
                printf("Match false!\n");
                goto Mismatch;
            } else {
                a = b;
                b = b->pre;
                free(a);
            }
        }
    }
    if(b->brackets == '$'){
        printf("Match succeed!\n");
    } else {
        printf("Match false!\n");
    }
    Mismatch:
    return 0;
}
