#include <iostream>
#include <vector>
#include <climits>

int findMin(std::vector<int>& nums){
    int st = 0,end = nums.size()-1;
    
    while(st < end){
        if(nums[st] < nums[end]){
            return nums[st];
        }
        int mid = st +(end-st)/2;
        if(nums[mid] > nums[end]){
            st = mid+1;
        }else{
            end = mid;
        }
    }
    return nums[st];
}

int main(){
    std::vector<int> nums{4,5,6,7,0,1,2};
    std::vector<int> nums1{3,4,5,1,2};

    std::cout << findMin(nums) << std::endl;
    std::cout << findMin(nums1) << std::endl;

    return 0;
}