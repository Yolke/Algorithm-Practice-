#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    for(int i=0 ; i<numsSize ; i++)
    {
        if(nums[i]!=val)
        {
            nums[k++]=nums[i];
        }
    }
    return k;
}


int main(){
    int x[]= {3,2,2,3};
    int size=  4;
    int val = 3;

    int k = removeElement(x,size,val);
    printf("k = %d\n",k);
    for(int i = 0;i< size;i++)printf("%d, ",x[i]);
}