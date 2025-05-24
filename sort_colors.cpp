#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This is the optimize  way to solve the problem
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            count0++;
        else if (nums[i] == 1)
            count1++;
        else
            count2++;
    }

    int idx = 0;
    for (int i = 0; i < count0; i++)
    {
        nums[idx++] = 0;
    }
    for (int i = 0; i < count1; i++)
    {
        nums[idx++] = 1;
    }
    for (int i = 0; i < count2; i++)
    {
        nums[idx++] = 2;
    }
}

// This is the optimal way to solve the problem
void SortColors(vector<int>& nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++, mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else // nums[mid] == 2
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

    // Sorting a vector by the default C++ function.
    sort(nums.begin(), nums.end());
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}