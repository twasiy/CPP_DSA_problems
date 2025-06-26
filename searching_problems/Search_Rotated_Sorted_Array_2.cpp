#include<iostream>
#include<vector>

bool search(std::vector<int>& nums, int target) {
    int st = 0,end = nums.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;

        if(nums[mid] == target) return true;
        // Handle duplicates: when nums[st] == nums[mid] == nums[end]
        if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
            st++;end--;
        }else if(nums[st] <= nums[mid]){ // Left half is sorted
            if(nums[st] <= target && target < nums[mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }else{ // right half is sorted
            if(nums[mid] <= nums[end]){
                if(nums[mid] < target && target <= nums[end]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
    }
    return false;
}

int main(){
    std::vector<int> nums{2,5,6,0,0,1,2};

    int target{0};
    std::cout << search(nums,target) << std::endl;

    return 0;
}
