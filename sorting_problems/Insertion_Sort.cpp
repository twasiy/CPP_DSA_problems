#include <iostream>

void InsertionSort(int arr[],int n){ //worst case time complexity O(n^2)
	for(int i = 0;i<n-1;i++){
		int j = i+1;
		while(j >= 1 && arr[j] < arr[j-1]){
			std::swap(arr[j],arr[j-1]);
			j--;
		}
	}
}

int main(){
	int arr[]{5,10,1,4,2,3,20};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	InsertionSort(arr,n);
	for(int i = 0;i<n;i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}