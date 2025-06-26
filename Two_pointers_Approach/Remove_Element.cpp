#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val){
    if (nums.size() == 0) return 0;
    int i = 0;
    for(int j = 0;j < nums.size();j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main(){
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int val{2};

    std::cout << removeElement(nums,val) << std::endl;

    return 0;
}