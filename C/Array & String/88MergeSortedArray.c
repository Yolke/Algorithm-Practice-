#include <stdio.h>
#include <stdlib.h>



//Developped by myself
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
     int idxX = m - 1;
    int idxY = n - 1;

    while (idxX >= 0 && idxY >= 0) {
        if (nums1[idxX] > nums2[idxY]) {
            nums1[nums1Size - 1] = nums1[idxX];
            idxX--;
        } else {
            nums1[nums1Size - 1] = nums2[idxY];
            idxY--;
        }
        nums1Size--;
    }

    while (idxY >= 0) {
        nums1[nums1Size - 1] = nums2[idxY];
        idxY--;
        nums1Size--;
    }
}

//Corection : Append Tab2 to Tab1 then bubble sort ( the time execution is barely the same between the two solution )
void OPmerge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int size=m+n;
    for(int i=0;i<n;i++){
        nums1[m+i] = nums2[i];
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(nums1[j] > nums1[j+1]){
                int temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }   
    }
}


int main(){


    int x[] = {1,2,3,0,0,0};
    int m = 3;
    int sizeX = 6;

    int y[] = {2,5,6};
    int n = 3;

    OPmerge(x,sizeX,m,y,n,n);
    
    for(int i = 0;i<sizeX;i++)printf("%d  ",x[i]);

    return 0;
}