#include <iostream>
#include <vector>

//Here I use merge sort to solve this problem. but for this problem merge sort is not the ideal.you should use two pointer approach.
void merge(std::vector<int>& nums,int st,int mid,int end){
	std::vector<int> temp;
	
	int i = st,j = mid+1;
	while(i <= mid && j <= end){
		if(nums[i] <= nums[j]){
			temp.push_back(nums[i++]);
		}else{
			temp.push_back(nums[j++]);
		}
	}
	while(i <= mid){
		temp.push_back(nums[i++]);
	}
	while(j <= end){
		temp.push_back(nums[j++]);
	}
	
	int n = temp.size();
	for(int i = 0;i < n;i++){
		nums[i+st] = temp[i];
	}
}
void sort(std::vector<int>& nums,int st,int end){
	if(st < end){
		int mid = st + (end - st)/2;
		
		sort(nums,st,mid);
		sort(nums,mid+1,end);
		
		merge(nums,st,mid,end);
	}
}
std::vector<int> sortedsquares(std::vector<int>& nums){
    int n = nums.size();
	
    for(int i = 0;i<n;i++){
		nums[i] *= nums[i];
	}
	// Sorting the element
	sort(nums,0,n-1);
	return nums;
}

//Two pointers approach  is the optimal for this problem
std::vector<int> sortedSquares(std::vector<int>& nums){
    int n = nums.size();
    int st = 0, end = n - 1;
    std::vector<int> result(n);
    
    int idx = n - 1;
    while (st <= end) {
        int leftSq = nums[st] * nums[st];
        int rightSq = nums[end] * nums[end];
        
        if (leftSq > rightSq) {
            result[idx--] = leftSq;
            st++;
        } else {
            result[idx--] = rightSq;
            end--;
        }
    }
    return result;
}

int main(){
	
	std::vector<int> nums{-4,-1,0,3,10};
	
	// This is sorting approch
	auto value = sortedsquares(nums);
	for(auto val:value){
		std::cout << val << " ";
	}
	std::cout << std::endl;
	
	// // This is two pointer approch
	auto value1 = sortedSquares(nums);
	for(auto val:value1){
		std::cout << val << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
