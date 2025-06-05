#include <iostream>
#include <vector>
#include <algorithm>

void getAllSubsets(std::vector<int> &nums, std::vector<int> &ans, int i, std::vector<std::vector<int>> &allSubsets){
    
    if (i == nums.size()){
        allSubsets.push_back(ans);
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    ans.pop_back();

    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1]){
        idx++;
    }
    // exclude
    getAllSubsets(nums, ans, idx, allSubsets);
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums){

    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> allSubsets;
    std::vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main(){
    // Example usage:
    std::vector<int> nums{1, 2, 3};

    std::vector<std::vector<int>> result = subsetsWithDup(nums);
    for (const auto &subset : result){
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i){
            std::cout << subset[i];
            if (i + 1 < subset.size()) std::cout << ", ";
        std::cout << "]" << std::endl;
        }
    }
    return 0;
}