#include<iostream>
#include<vector>

std::vector<int> searchRange(std::vector<int>& nums, int target){
    int n = nums.size();
    if(n == 0) return {-1, -1};

    int left = -1, right = -1;

    // First occurrence
    int st = 0, end = n - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if(nums[mid] >= target){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
        if(nums[mid] == target) left = mid;
    }

    // Last occurrence
    st = 0, end = n - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if(nums[mid] <= target){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
        if(nums[mid] == target) right = mid;
    }
    if(left == -1 || right == -1) return {-1, -1};
    return {left, right};
}

int main(){

    std::vector<int> nums{5,7,7,8,8,10};
    auto value = searchRange(nums,8);
    for(auto val:value){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}