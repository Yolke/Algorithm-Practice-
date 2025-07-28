#include <stdio.h>
#include <stdlib.h>



int reverseInterger(int x){

    int reversed = 0;
    while (x != 0){
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return reversed;
}


int main(){

    int x =reverseInterger(123);
    printf("Reversed = %d",x);

    return 0;    

}