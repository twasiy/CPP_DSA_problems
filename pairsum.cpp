#include<iostream>
#include<vector>
#include<algorithm>
////The vector function for getting pairsum of an vector.
std::vector <int> pairsum(std::vector<int>nums,int target){
    std::vector <int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

////This is the vector function for getting pairsum of an array in the optimize way.


std::vector<int> twoSum(std::vector<int> &nums, int target){
    int n = nums.size();
    std::vector<std::pair<int, int>> arr; // value, original index

    for (int i = 0; i < n; i++){
        arr.push_back({nums[i], i});
    }

    std::sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;

    while (left < right){
        int sum = arr[left].first + arr[right].first;
        if (sum == target){
            return {arr[left].second, arr[right].second};
        }else if (sum < target){
            left++;
        }else{
            right--;
        }
    }
    return {}; // No pair found
}

int main(){
    std::vector<int> nums = {2,7,11,15};
    int target = 26;

    //This is brute force approch
    std::vector<int>ans = pairsum(nums,target);
    std::cout << ans[0] << "," << ans[1] << std::endl;

    //This is two pointer approch
    std::vector<int> value = twoSum(nums, target);
    std::cout << value[0] << "," << value[1] << std::endl;

    return 0;
}