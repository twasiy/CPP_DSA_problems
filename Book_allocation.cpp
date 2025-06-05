#include <iostream>
#include <vector>

bool isValid(std::vector<int>& arr,int n ,int m, int mid){ //O(n)
    int students = 1,pages = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] > mid){
            return false;
        }
        if (pages + arr[i] <= mid){
            pages +=arr[i];
        }else{
            students++;
            pages = arr[i];
        }
    }
    return (students > m)? false:true;
}


int allocateBooks(std::vector<int> &arr,int n,int m){//O(logN * n)

    if (m > n) return -1;
    int sum = 0;
    for (int i = 0; i < n; i++){ //O(n)
        sum+=arr[i];
    }

    int ans = -1;
    int st = 0,end = sum; //range of possible ans.

    while (st <= end){ //O(logN)
        int mid = st+(end-st)/2;

        if (isValid(arr,n,m ,mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
   return ans; 
}

int main(){
    std::vector<int> arr{2,1,3,4};
    int n = 4, m = 2;

    std::cout << allocateBooks(arr,n,m) << std::endl;
    
    return 0;
}