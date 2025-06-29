#include <iostream>
#include <vector>

void getAllSubsets(std::vector<int> &nums, std::vector<int> &ans, int i, std::vector<std::vector<int>> &allsubsets){
    int n = nums.size();
    if (i == n){
        allsubsets.push_back({ans});
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allsubsets);

    ans.pop_back();
    // exclude
    getAllSubsets(nums, ans, i + 1, allsubsets);
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums){
    std::vector<std::vector<int>> allsubsets;
    std::vector<int> ans;

    getAllSubsets(nums,ans,0, allsubsets);
    return allsubsets;
}

int main(){
    std::vector<int> nums{1,2,3,4,5};
    auto value = subsets(nums);
    for(auto val:value){
        for(auto v:val){
            std::cout << v << " ";
        }
    std::cout << std::endl;
    }
    //std::cout << "\t";
    return 0;
}
