#include <iostream>
#include <vector>

//If you want custom sorting logic for this problem then it is for you 
void merge(std::vector<int>& nums,int st,int mid,int end){
    std::vector<int> temp;
    
    //Collecting the even number from both section
    int i = st, j = mid+1;
    while(i <= mid){
        if(nums[i] % 2 == 0){
            temp.push_back(nums[i]);
        }
        i++;
    }
    while(j <= end){
        if(nums[j] % 2 == 0){
            temp.push_back(nums[j]);
        }
        j++;
    }

    //Collecting the odd number from both section
    i = st, j = mid+1;
    while(i <= mid){
        if(nums[i] % 2 != 0){
            temp.push_back(nums[i]);
        }
        i++;
    }
    while(j <= end){
        if(nums[j] % 2 != 0){
            temp.push_back(nums[j]);
        }
        j++;
    }

    //Copying the values temp to the nums
	for(int idx = 0;idx<temp.size();idx++){
		nums[st+idx] = temp[idx];
	}
}

void SortArrayByParity(std::vector<int>& nums, int st, int end){
    if(st < end){
        int mid = st + (end-st)/2;
        SortArrayByParity(nums,st,mid);
        SortArrayByParity(nums,mid+1,end);
        
        merge(nums,st,mid,end);
    }
}

//For the leetcode problem this is optimal.
void sortarraybypairity(std::vector<int>& nums){
    int n = nums.size();
    int i = 0,j = n-1;
    while(i <= j){
        if(nums[i] % 2 == 0)
            i++;
        else if(nums[j] % 2 != 0)
            j--;
        else{
            std::swap(nums[i],nums[j]);
            i++;j--;
        }
    }
}

int main(){
    std::vector<int> nums{3,1,2,4};
    int n = nums.size();

    //Custom sorting function calling 
    SortArrayByParity(nums,0,n-1);
    for(int value : nums){
        std::cout << value << " ";
    }
    std::cout << std::endl;

    //Optimal function calling 
    sortarraybypairity(nums);
    for(int value : nums){
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}