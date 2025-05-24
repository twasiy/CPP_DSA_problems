#include<iostream>
#include<vector>
using namespace std;

int main(){
    ////Buy and sell approch problem.
    vector <int> prices = {7,1,5,3,6,4};
    int maxprofit = 0, bestbuy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestbuy)
        {
            maxprofit = max(maxprofit,prices[i] - bestbuy);
        }
        bestbuy = min(bestbuy,prices[i]); 
    }
    
    return 0;
}