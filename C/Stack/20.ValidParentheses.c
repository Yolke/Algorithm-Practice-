#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack {
    int top;
    char* item; 
} *Stack;

bool empty(Stack S){
    if( S->top == -1 ) return 1;
    return 0;
}

void push(Stack S, char v){
    S->top++;
    S->item[S->top] = v;
}

char pop(Stack S){
    char r = S->item[S->top];
    S->top--;
    return r;
}

bool isValid(char* s) {
    int len = strlen(s);
    Stack stk = (Stack) malloc (sizeof(struct stack) * len);
    stk->top = -1;
    stk->item = (char*) malloc (sizeof(char) * len);

    for(int i=0; i < len; i++){
        switch(s[i]){
            case '(': push(stk, ')'); break;
            case '[': push(stk, ']'); break;
            case '{': push(stk, '}'); break;
            default: 
                if(empty(stk) || s[i] != pop(stk)){
                    free(stk->item);
                    free(stk);
                    return false;
                }
        }
    }
    bool r = empty(stk);
    free(stk->item);
    free(stk);
    return r;
}


int main(){
    return 0;
}