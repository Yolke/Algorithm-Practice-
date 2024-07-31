#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    if (numsSize <= 1) return true;

    int jumpsNeeded = 1;

    for (int i = numsSize - 2; i >= 0; --i) {
        if (nums[i] >= jumpsNeeded) jumpsNeeded = 1;
        else jumpsNeeded++;
    }
    return nums[0] >= jumpsNeeded;
}






int main(){
    int x[] = {2,3,1,1,4};

    printf("Result : %d\n",canJump(x,5));

    return 0;
}