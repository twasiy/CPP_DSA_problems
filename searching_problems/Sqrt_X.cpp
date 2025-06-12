#include<iostream>

int mySqrt(int x) {
    if (x < 2) return x;
    int left = 1, right = x / 2, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) {  // To avoid mid * mid overflow
            ans = mid;         // mid might be the answer
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    int x{16};
    std::cout << mySqrt(x) << std::endl;

    return 0;
}