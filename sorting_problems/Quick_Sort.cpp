#include <iostream>
#include <vector>

//In this helper function the pivot value is the last value of the array.
int partition_func(std::vector<int>& nums,int st,int end){
	int i = st,pivot = nums[end];
	for(int j = st;j<end;j++){
		if(nums[j] <= pivot){ //If nums[j] is smaller than the pivot then it's position will be the first index and so on.
			std::swap(nums[j],nums[i]);
			i++;
		}
	}
	//swaping the end value to it's pivot index.
	std::swap(nums[end],nums[i]);
	return i;
}

//In this helper function the pivot value is the first value of the array.
int partition_fun(std::vector<int>& nums,int st,int end){
	int i = end,pivot = nums[st];
	for(int j = end;j>st;j--){
		if(nums[j] >= pivot){ //If nums[j] is smaller than the pivot then it's position will be the first index and so on.
			std::swap(nums[j],nums[i]);
			i--;
		}
	}
	//swaping the end value to it's pivot index.
	std::swap(nums[st],nums[i]);
	return i;
}

//Main sorting function
void quicksort(std::vector<int>& nums,int st, int end){
	if(st < end){
		int pivotIndex = partition_func(nums,st,end);
		
		//The pivot and partition rule(based on divide and conqure)
		quicksort(nums,st,pivotIndex-1); //Left half
		quicksort(nums,pivotIndex+1,end); //Right half
	}
}

//Driver code
int main(){
	std::vector<int> nums= {12,13,17,19,11,21,29,23,16,25,22};
	int n = nums.size();
	
	quicksort(nums,0,n-1);
	
	for(auto val:nums){
		std::cout << val << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
