#include <iostream>
#include <vector>

////This is called Binary search Algorithm likely two pointer approch.
int binary_search(std::vector<int> nums, int tar, int st, int end){
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (tar > nums[mid]){
            st = mid + 1; // 2nd half;
        }else if (tar < nums[mid]){
            end = mid - 1; // 1st half;
        }else{
            return mid;
        }
    }
    return -1; // Return -1 if the target is not found
}

////This is called Binary search Algorithm with recursive function
int binary_search_recursive(std::vector<int> nums, int tar, int st, int end){
    if (st <= end){
        int mid = st + (end - st) / 2;
        if (tar > nums[mid]){
            return binary_search_recursive(nums, tar, mid + 1, end); // 2nd half;
        }else if (tar < nums[mid]){
            return binary_search_recursive(nums, tar, st, mid - 1); // 1st half;
        }else{
            return mid;
        }
    }
    return -1; // Return -1 if the target is not found
}

int main(){
    std::vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int n = nums.size();
    int st = 0, end = n - 1;
    int tar = 12;

    std::cout << binary_search(nums, tar, st, end) << std::endl;
    
    std::cout << binary_search_recursive(nums, tar, st, end) << std::endl;
    return 0;
}