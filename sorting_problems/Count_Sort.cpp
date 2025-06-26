#include <iostream>
#include <vector>
#include <climits>

int maximum(std::vector<int>& nums,int n){
	int max = INT_MIN;
	for(int i = 0;i < n;i++){
		if(nums[i] > max){
			max = nums[i];
		}
	}
	return max;
}

void CountSort(std::vector<int>& nums,int n){
	int max = maximum(nums,n);
	std::vector<int> count(max+1,0); // Initialize with the value 0;

	// Increment the corresponding index in the count array
	for(int i = 0;i < n;i++){
		count[nums[i]] += 1;
	}
	int idx = 0,j = 0;
	while(idx < max+1){
		if(count[idx] > 0){
			nums[j++] = idx;
			count[idx] -= 1;
		}else{
			idx++;
		}
	}
}

//Driver code
int main(){
	std::vector<int> nums{3,1,9,7,1,2,4};
	int n = nums.size();
	
	CountSort(nums,n);
	for(int val:nums){
		std::cout << val << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
