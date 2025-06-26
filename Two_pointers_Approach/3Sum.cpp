#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

////This is the brute force approch for solving the Threesum problem;
std::vector<std::vector<int>> ThreeSum(std::vector<int> &nums){
    std::vector<std::vector<int>> ans;

    std::set<std::vector<int>> s; // set<uniqueTriplets>
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            for (int k = j + 1; k < nums.size(); k++){
                if (nums[i] + nums[j] + nums[k] == 0){
                    std::vector<int> trip = {nums[i], nums[j], nums[k]};
                    std::sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

////This is optimized way to solve the problem.we use hashing for the optimized way to solve the problem
std::vector<std::vector<int>> ThreeSum_optimized(std::vector<int> &nums){
    std::set<std::vector<int>> uniqueTriplets;

    for (int i = 0; i < nums.size(); i++){
        int tar = -nums[i];
        std::set<int> s;

        for (int j = i + 1; j < nums.size(); j++){
            int third = tar - nums[j];
            if (s.find(third) != s.end()){
                std::vector<int> trip = {nums[i], nums[j], third};
                std::sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    std::vector<std::vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

////This is the most optimal approch to solve the problem this is called Two pointer's approch.
std::vector<std::vector<int>> ThreeSum_optimal(std::vector<int> &nums){
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = nums.size() - 1;

        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0){
                j++;
            }else if (sum > 0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
            }
        }
    }
    return ans;
}

int main(){
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // you just have to change the function name in this vector;
    std::vector<std::vector<int>> result = ThreeSum_optimized(nums);

    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[0].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}