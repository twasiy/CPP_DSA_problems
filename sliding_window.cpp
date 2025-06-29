#include <iostream>
#include <vector>

int subarray_sum(std::vector<int>& nums,int w){
	int n = nums.size();
	
	int current = 0;
	for(int i = 0;i < w;i++){
		current += nums[i];
	}
	
	int maxval = current;
	for(int j = 1;j < n-w;j++){
		current = current-nums[j-1]+nums[j+w-1];
		if(current > maxval){
			maxval = current;
		}
	}
	return maxval;
}

int main(){
	std::vector<int> nums{12,17,14,19,18,11,15,16,10,13};
	int w{4};
	std::cout << subarray_sum(nums,w) << std::endl;
	
	return 0;
}
