#include <iostream>
#include <vector>

//Heapify algorithm
void heapify(std::vector<int>& num,int n,int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left < n && num[largest] < num[left]){
		largest = left;
	}
	if(right < n && num[largest] < num[right]){
		largest = right;
	}
	if(largest != i){
		std::swap(num[largest],num[i]);
		heapify(num,n,largest);
	}
}

//Building Heap
std::vector<int> BuildHeap(std::vector<int>& num){
	int n = num.size();
	for(int i = n/2-1;i >= 0;i--){
		heapify(num,n,i);
	}
	return num;
}

//This is heap sort algorithm
void heapsort(std::vector<int>& num,int n){
    int size = n;
    while(size > 0){
        std::swap(num[size-1],num[0]);
        size--;
        heapify(num,size,0);
    }
}

// printing a vector
void printvector(const std::vector<int>& vec){
    int n = vec.size();
    std::cout << "[";
    for (int i = 0; i < n; i++){
        std::cout << vec[i];
        if (i != n - 1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::vector<int> num{12,31,35,8,32,17};
    int n = num.size();
    BuildHeap(num);
    heapsort(num,n);
    std::cout << "After Sorting:";
    for(int i = 0;i < n; i++){
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}