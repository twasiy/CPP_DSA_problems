#include <iostream>
#include <vector>

void merge(std::vector<int>& arr,int st, int mid,int end){
	std::vector<int> temp;
	int i = st,j = mid+1;
	
	while(i <= mid && j <= end){
		if(arr[i] <= arr[j]){
			temp.push_back(arr[i++]);
		}else{
			temp.push_back(arr[j++]);
		}
	}
	
	while(i <= mid){
		temp.push_back(arr[i++]);
	}
	while(j <= end){
		temp.push_back(arr[j++]);
	}
	
	int n = temp.size();
	for(int idx = 0;idx<n;idx++){
		arr[idx+st] = temp[idx];
	}
}

void mergesort(std::vector<int>& arr,int st,int end){
	if(st < end){
		int mid = st + (end-st)/2;
		
		//The divide and conqure rule
		mergesort(arr,st,mid);
		mergesort(arr,mid+1,end);
		
		merge(arr,st, mid,end);
	}
}

int main(){
	std::vector<int> arr = {12,13,65,34,98,78,90,54,91};
	int n = arr.size();
	mergesort(arr,0,n-1);
	
	for(int i = 0;i<n;i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
