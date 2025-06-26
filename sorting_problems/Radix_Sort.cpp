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

void CountSort(std::vector<int>& nums, int n, int exp){
	std::vector<int> output(n);
	int count[10] = {0};

	// Store count of occurrences in count[]
	for (int i = 0; i < n; i++){
		int digit = (nums[i] / exp) % 10;
		count[digit]++;
	}

	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (int i = 1; i < 10; i++){
		count[i] += count[i - 1];
	}

	// Build the output array
	for (int i = n - 1; i >= 0; i--){
		int digit = (nums[i] / exp) % 10;
		output[count[digit] - 1] = nums[i];
		count[digit]--;
	}

	// Copy the output array to nums[]
	for (int i = 0; i < n; i++){
		nums[i] = output[i];
	}
}

void radixsort(std::vector<int>& nums, int n){
    int m = maximum(nums, n);

    for (int exp = 1; m / exp > 0; exp *= 10){
        CountSort(nums, n, exp);
    }
}

int main(){
    std::vector<int> nums{123,321,435,235,786,567,908,789,987,647,286,351,754,192,456,678};
    int n = nums.size();
    
    radixsort(nums,n);
    for(auto val:nums){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}