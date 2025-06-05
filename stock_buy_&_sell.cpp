#include<iostream>
#include<vector>

int main(){
    ////Buy and sell approch problem.
    std::vector <int> prices = {7,1,5,3,6,4};
    int maxprofit = 0, bestbuy = prices[0];

    for (int i = 1; i < prices.size(); i++){
        if (prices[i] > bestbuy) maxprofit = std::max(maxprofit,prices[i] - bestbuy);
        bestbuy = std::min(bestbuy,prices[i]); 
    }
    return 0;
}