#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int> &nums){
    // find the pivot
    int pivot = -1, n = nums.size();

    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i + 1]){
            pivot = i;
            break;
        }
    }

    if (pivot == -1){
        std::reverse(nums.begin(), nums.end()); // in place changes
        return;
    }
    // 2nd step : next larger element
    for (int i = n - 1; i > pivot; i--){
        if (nums[i] > nums[pivot]){
            std::swap(nums[i], nums[pivot]);
            break;
        }
    }
    // 3rd step : revese (piv+1 to n-1);
    //  revese(nums.begin() + pivot +1, nums.end());
    int i = pivot + 1, j = n - 1;
    while (i <= j){
        std::swap(nums[i++], nums[j--]);
    }
}

int main(){

    return 0;
}