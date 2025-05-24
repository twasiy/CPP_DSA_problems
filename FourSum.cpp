#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

////This is the function find such 4 values that are equals to zero when we calculate the sum of them.

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int tar)
{
    std::vector<std::vector<int>> ans;
    int n = nums.size();

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int p = j + 1, q = n - 1;

            while (p < q)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                if (sum == tar)
                {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    while (p < q && nums[p] == nums[p - 1])
                        p++;
                    while (p < q && nums[q] == nums[q + 1])
                        q--;
                }
                else if (sum < tar)
                {
                    p++;
                }
                else
                {
                    q--;
                }
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}