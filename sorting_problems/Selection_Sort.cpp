#include <iostream>
#include <climits>

void SelectionSort(int arr[],int n){
	for(int i = 0;i<n-1;i++){
		int min = INT_MAX;
		int minIdx = -1;
		for(int j = i;j<n;j++){
			if(min>arr[j]){
				min = arr[j];
				minIdx = j;
			}
		}
		//Swaping the minimum value at first of the array.
		std::swap(arr[i],arr[minIdx]);
	}
}

int main(){
	int arr[]{5,10,1,4,2,3,20};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	SelectionSort(arr,n);
	for(int i = 0;i<n;i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
