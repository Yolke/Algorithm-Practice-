#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {

    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        while (left < right && !isalnum(s[left])) {
            left++;
        }

        while (left < right && !isalnum(s[right])) {
            right--;
        }
        

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int main(){
    char c[] = "zeq  ,. qez";
    printf("Test : %d",isPalindrome(c));

    return 0;
}