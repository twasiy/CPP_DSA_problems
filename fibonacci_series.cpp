////Fibonacci series wih better time complextiy.
#include <iostream>
using namespace std;

int main()
{
    int n = 10000;
    long long a = 1, b = 1;

    cout << a << " " << b << " ";

    for (int i = 2; i < n; i++)
    {
        long long next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;

    return 0;
}
