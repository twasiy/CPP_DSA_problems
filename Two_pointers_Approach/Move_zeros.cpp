#include<iostream>
#include<vector>

void moveZeroes(std::vector<int>& nums) {
	int left = 0; // Points to the position where next non-zero should be place
	int size = nums.size();
	
	// Move all non-zero elements to the front
	for (int right = 0; right < size; right++) {
		if (nums[right] != 0) {
			nums[left] = nums[right];
			left++;
		}
	}
	// Fill remaining positions with zeros
	while (left < size){
		nums[left] = 0;
		left++;
	}
}

int main(){
	
	std::vector<int> nums{0,1,0,3,12};
	
	moveZeroes(nums);
	for(int num:nums){
		std::cout << num << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
