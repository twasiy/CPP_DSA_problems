#include<iostream>

int arrangeCoins(int n) {
    int st = 0,end = n;
    int result = 0;

    while(st <= end){
        int mid = st + (end - st) / 2;
        long long sum = (1LL * mid * (mid + 1)) / 2;  // Using 1LL to avoid overflow

        if(sum == n){
            return mid;
        }else if(sum < n){
            result = mid; // Possible answer
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return result;
}

int main(){
    int n{8};
    std::cout << arrangeCoins(n) << std::endl;

    return 0;
}