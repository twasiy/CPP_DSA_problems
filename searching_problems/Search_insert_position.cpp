#include<iostream>
#include<vector>

int searchInsert(std::vector<int>& nums, int target) {
    int st = 0,end = nums.size()-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(target == nums[mid]){
            return mid;
        }else if(target < nums[mid]){
            end = mid-1;
        }else{
            st = mid+1;;
        }
    }
    return st;
}

int main(){
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};

    int target{7};
    std::cout << searchInsert(nums,target) << std::endl;

    return 0;
}