#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char *s,char *t){
    int size = strlen(t);
    if(strlen(s) == 0) return true;
    int idx = 0;
    for(int i = 0;i<size;i++){
        if(t[i] == s[idx]){
            idx++;
        }
        if(idx == strlen(s)-1){
            return true;
        }
    }
    return false;
}


int main(){
    printf("%d",isSubsequence("","ahbgdc"));
    return 0;
}