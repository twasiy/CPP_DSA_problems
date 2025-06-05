#include<iostream>
#include<vector>

////product of an array except self in optimal approch.(Tow pointer approch)
std::vector<int> productExceptSelf(std::vector<int> &nums){
    int n = nums.size();
    std::vector<int> ans(n, 1);
    // Step 1: Fill ans with prefix products
    int prefix = 1;
    for (int i = 0; i < n; ++i){
        ans[i] = prefix;
        prefix *= nums[i];
    }
    // Step 2: Multiply with suffix products (in reverse)
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i){
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;
}

int main(){
    
    std::vector <int> nums = {1,2,3,4};
    int n = nums.size();

    ////product of an array except self in normal brute force approch.
    std::vector <int> ans(n,1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                ans[i] *= nums[j];
            }
        }
    }
    std::cout << "[";
    for (int i = 0; i < n; i++){
        std::cout << ans[i];
        if (i != n - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}