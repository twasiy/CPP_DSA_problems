#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////This is brute force approch of getting primes in a range;
int primes(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; (j * j) <= i; j++)
        {
            if (i % j != 0)
            {
                count++;
            }
        }
    }
    return count;
}

////This is optimal approch of getting primes in a range.
int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    vector<bool> isPrime(n, true); // n, not n+1
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return count(isPrime.begin(), isPrime.end(), true);
}

int main(){

    int n = 10;
    cout << "This is by brute force:" << primes(n) << endl;

    cout << "This is by optimal:" << countPrimes(n) << endl;
    
    return 0;
}