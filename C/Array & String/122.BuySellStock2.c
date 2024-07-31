#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices,int pricesSize){
    int maxL = 0;
    int max = 0;
    int current = prices[0];
    for(int i = 1;i < pricesSize;i++){
        if(prices[i-1] > prices[i]){
            current = prices[i];
            max += maxL;
            maxL = 0;
        }
        else{
            maxL = prices[i] - current;
        }  
    }
    max += maxL;

    return max;
}
//Optimale solution 
int OPmaxProfit(int* prices, int pricesSize) {
    int profit = 0;

    for (int i = 1; i < pricesSize; i++)
        if (prices[i - 1] < prices[i])
            profit += prices[i] - prices[i - 1];

    return profit;
}


int main(){
    int t[] = {7,6,4,3,1};
    int x = maxProfit(t,6);
    printf("%d",x);
    return 0;
}