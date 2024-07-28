#include <stdlib.h>
#include <stdio.h>

int positive_mod(int a, int b) {
    int mod = a % b;
    if (mod < 0) {
        mod += b;
    }
    return mod;
}

void rotate(int* nums, int numsSize, int k) {
    int *result = malloc(sizeof(int)*numsSize);
    for(int i = 0;i < numsSize;i++){
        result[i] = nums[positive_mod((i-k),numsSize)];
    }
    for(int i = 0;i < numsSize;i++){
        nums[i]=result[i];
    }

}

void OProtate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int i;
    int j = 0;
    int z = 0;
    int temp1;
    int temp2;
    while (j < numsSize) {
        i = z;
        temp1 = nums[i];
        i = (i + k) % numsSize;
        while (i != z) {
            temp2 = nums[i];
            nums[i] = temp1;
            temp1 = temp2;
            i = (i + k) % numsSize;
            j++;
        }
        nums[i] = temp1;
        j++;
        z++;
    }
}


int main(){

    int x[] = {1,2,3,4,5};
    rotate(x,5,2);
    for(int i = 0;i<5;i++)printf("%d, ",x[i]);



    return 0;
}