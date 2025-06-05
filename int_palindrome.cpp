#include <iostream>
#include<climits>

bool palindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    long temp = x;
    long reversed = 0;

    while (temp > 0){
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    if (x == reversed){
        return true;
    }else{
        return false;
    }
}

// Another optimized solution of palindrome.
bool isPalindrome(int num){
    // Negative numbers are never palindrome
    if (num < 0 || (num % 10 == 0 && num != 0)) return false;

    int reversed = 0;

    while (num > reversed){
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    // For even-length numbers: num == reversed
    // For odd-length: num == reversed/10 (middle digit doesn't matter)
    return (num == reversed || num == reversed / 10);
}

////This is okay when you have limited data and no condition that you can't go exceed the int 32 .
int reverseNum(int n){
    int reverse = 0;
    while (n != 0){
        int digit = n % 10;
        reverse = (reverse * 10) + digit;
        n /= 10;
    }
    return reverse;
}

////Works on worst case when you can't go exceed int 32.
int reverse(int n){
    int reversenum = 0;
    while (n != 0){
        int digit = n % 10;

        // Check for overflow before actually doing the operation
        if (reversenum > INT_MAX / 10 || (reversenum == INT_MAX / 10 && digit > 7)) return 0;
        if (reversenum < INT_MIN / 10 || (reversenum == INT_MIN / 10 && digit < -8)) return 0;
        reversenum = reversenum * 10 + digit;
        n /= 10;
    }
    return reversenum;
}

bool isPalindrome(int n){
    if (n < 0) return false;
    int revnum = reverse(n);
    return n == revnum;
}

int main(){

    int x = 121;
    std::cout << palindrome(x) << std::endl;

    std::cout << isPalindrome(x) << std::endl;

    return 0;
}