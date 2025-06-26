#include <iostream>
#include <vector>

/* In this I have used quick sort but you can use the std::sort function to solve this.
 * just change the heightChecker function in line 32 enough.
 */

int partition(std::vector<int>& heights, int st , int end){
	int i = st , pivot = heights[end];

	for(int j = st;j < end;j++){
		if(heights[j] <= pivot){
			std::swap(heights[j],heights[i]);
			i++;
		}
	}
	std::swap(heights[end],heights[i]);
	return i;
}

void sort(std::vector<int>& heights,int st,int end){
	if(st < end){
		int pivotIndex = partition(heights,st,end);
		
		sort(heights,st,pivotIndex-1);
		sort(heights,pivotIndex+1,end);
	}
}

int heightChecker(std::vector<int>& heights){
	int n = heights.size();
	std::vector<int> temp = heights;
    sort(temp,0,n-1);
    
    int count = 0;
    for(int i = 0;i < n;i++){
		if(heights[i] != temp[i]){
			count++;
		}
	}
	return count;
}

int main(){
	
	std::vector<int> heights{1,1,4,2,1,3};
	
	int value = heightChecker(heights);
	std::cout << value << std::endl;
	
	return 0;
}
