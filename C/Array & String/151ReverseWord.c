#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Reverse word

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

char* reverseWords(char* s) {
    while (*s == ' ') {
        s++;
    }
    int len = strlen(s);
    while (len > 0 && s[len - 1] == ' ') {
        s[--len] = '\0';
    }

    char* word_begin = s;
    char* temp = s;
    while (*temp) {
        temp++;
        if (*temp == ' ' || *temp == '\0') {
            reverse(word_begin, temp - 1);

            word_begin = temp + 1;
        }
    }

    reverse(s, temp - 1);

    char* dest = s;
    temp = s;
    while (*temp) {
        if (*temp != ' ' || (*(temp + 1) != ' ' && *(temp + 1) != '\0')) {
            *dest++ = *temp;
        }
        temp++;
    }
    *dest = '\0';

    return s;
}


// Helper function to print the result for testing
void printString(char* str) {
    while (*str) {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

int main() {
    char s[] = "d  the   sky  is  blue  ";
    reverseWords(s);
    printString(s);  // Expected Output: "blue is sky the"
    return 0;
}
