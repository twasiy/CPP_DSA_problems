#include<iostream>
#include<vector>
using namespace std;

////product of an array except self in optimal approch.(Tow pointer approch)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    // Step 1: Fill ans with prefix products
    int prefix = 1;
    for (int i = 0; i < n; ++i)
    {
        ans[i] = prefix;
        prefix *= nums[i];
    }
    // Step 2: Multiply with suffix products (in reverse)
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}

int main(){
    
    vector <int> nums = {1,2,3,4};
    int n = nums.size();

    ////product of an array except self in normal brute force approch.
    vector <int> ans(n,1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                ans[i] *= nums[j];
            }
        }
    }

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (i != n - 1)
            cout << ",";
    }
    cout << "]" << endl;
}