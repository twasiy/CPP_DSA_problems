#include <iostream>
#include <vector>

std::vector<int> sortedSquares(std::vector<int> &nums){
    int n = nums.size();
    int st = 0, end = n - 1;
    std::vector<int> result(n);

    int idx = n - 1;
    while (st <= end){
        int leftSq = nums[st] * nums[st];
        int rightSq = nums[end] * nums[end];

        if (leftSq > rightSq){
            result[idx--] = leftSq;
            st++;
        }else{
            result[idx--] = rightSq;
            end--;
        }
    }
    return result;
}

int main(){
    std::vector<int> nums{1,2,3,4,5,6};

    std::vector<int> result = sortedSquares(nums);
    for(int val:result){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}