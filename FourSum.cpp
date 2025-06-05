#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

////This is the function find such 4 values that are equals to zero when we calculate the sum of them.
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int tar){
    std::vector<std::vector<int>> ans;
    std::vector<std::vector<int>> check{{-1}};

    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    bool statement{false};

    for (int i = 0; i < n - 3; i++){
        if (i > 0 && nums[i] == nums[i - 1])continue;

        for (int j = i + 1; j < n - 2; j++){
            if (j > i + 1 && nums[j] == nums[j - 1])continue;
            int p = j + 1, q = n - 1;

            while (p < q){
                long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];
                if (sum == tar){
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;q--;
                    statement = true;

                    while (p < q && nums[p] == nums[p - 1]) p++;
                    while (p < q && nums[q] == nums[q + 1]) q--;
                }else if (sum < tar){
                    p++;
                }else{
                    q--;
                }
            }
        }
    }
    if(!statement){
        return check;
    }
    return ans;
}

int main(){
    std::vector<int> nums {1,2,3,4,5,6,7,8,9};
    int target{45};
    auto result = fourSum(nums,target);
    for(const auto &it : result){
        for(auto i : it){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    return 0;
}