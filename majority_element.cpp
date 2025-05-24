#include<iostream>
#include<vector>
using namespace std;


////Calculating majority element of an vector
int majorityElement(vector<int> &vec)
{
    int n = vec.size();

    for (int val : vec)
    {
        int freq = 0;

        for (int el : vec)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            return val;
        }
    }
    return -1;
}

int main(){

        //The majority element of an vector
        vector<int> vec = {3,2,3};
        cout << majorityElement(vec) << endl;

    return 0;
}