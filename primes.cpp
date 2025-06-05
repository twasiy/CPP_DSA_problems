#include<iostream>
#include<vector>
#include<algorithm>

////This is brute force approch of getting primes in a range;
int primes(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 2; (j * j) <= i; j++){
            if (i % j != 0) count++;
        }
    }
    return count;
}

////This is optimal approch of getting primes in a range. This is called sieve of Eratosthenis
int countPrimes(int n)
{
    if (n <= 2) return 0;

    std::vector<bool> isPrime(n, true); // n, not n+1
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++){
        if (isPrime[i]){
            for (int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
    }
    return std::count(isPrime.begin(), isPrime.end(), true);
}

int main(){
    int n = 10;
    std::cout << "This is by brute force:" << primes(n) << std::endl;
    std::cout << "This is by optimal:" << countPrimes(n) << std::endl;
    return 0;
}