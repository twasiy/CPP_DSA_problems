#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int left = 0;
    for(int right = 1;right < nums.size();right++){
        if(nums[right] != nums[left]){
            left++;
            nums[left] = nums[right];
        }
    }
    return left+1;
}

int main(){
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    std::cout << removeDuplicates(nums) << std::endl;

    return 0;
}