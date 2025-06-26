#include<iostream>

//This is the binary search approch and it worked in O(log n);
bool isPerfectSquare(int num){
    long long left = 1, right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num){
            return true;
        }else if (square < num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

// It is general purpose solution for this problem.
bool valid_perfect_square(int num){
    if(num == 0) return false;
    if(num == 1) return true;

    for(long long i = 2;i*i<=num;i++){
        if(i*i == num) return true;
    }
    return false;
}

int main(){

    int num{4};
    std::cout << valid_perfect_square(num) << std::endl;
    std::cout << isPerfectSquare(num) << std::endl;

    return 0;
}