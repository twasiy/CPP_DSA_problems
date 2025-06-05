#include<iostream>

////Binary Exponentiation
double mypow(double x, int n){
    if (n == 0) return 1.0;
    if (x == 1.0) return 1.0;
    if (x == -1.0) return (n % 2 == 0) ? 1.0 : -1.0;
    if (x == 0.0) return (n <= 0) ? 1.0 : 0.0;
    
    long binFrom = n;
    if (n < 0){
        x = 1 / x;
        binFrom = -binFrom;
    }

    double ans = 1.0;
    while (binFrom > 0){
        if (binFrom % 2 == 1){
            ans *= x;
        }
        x *= x;
        binFrom /= 2;
    }
    return ans;
}

int main(){

    //normal exponential with normal way.this could happen TLE.
    int a = 5;
    int pow = 5;
    double result = 1.0;
    if(pow >= 0){
        for (int i = 1; i <= pow; i++){
            result *= a;
        }
    }else{
        for (int i = 1; i <= -pow; i++){
            result *= a;
        }
        result = 1.0/result;
    }
    std::cout << result << std::endl;

    return 0;
}