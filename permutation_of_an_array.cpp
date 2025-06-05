#include <iostream>
#include <algorithm>
#include <vector>

//Helper function for permute function.
void getPerms(std::vector<int>& nums,int idx,std::vector<std::vector<int>> & ans){
    if (idx == nums.size()){
        ans.push_back({nums});
        return;
    }
    for (int i = idx; i < nums.size(); i++){
        std::swap(nums[idx], nums[i]);//idx place => ith element choice.
        getPerms(nums,idx+1,ans);

        std::swap(nums[idx],nums[i]); // backtracking 
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums){
    std::vector<std::vector<int>> ans;
    getPerms(nums,0,ans);
    return ans;
}

int main(){
    std::vector<int> nums{1,2,3};
    auto result = permute(nums);
    
    //for this problem for each loop is much suitable and it works for this thing; 
    for (const auto& perm : result) {
        for (int num : perm){
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}