#include <iostream>
#include <vector>

void recursion_func(int n){
    if (n == 1){
        std::cout << "1" << std::endl;
        return;
    }
    std::cout << n << " ";
    recursion_func(n - 1);
}

// Factorial by using recursion.
int factorial(int n){
    if (n == 0){
        return 1;
    }
    return n * factorial(n - 1);
}

// sum of N nums using recursion.
int sum(int n){
    if (n == 1) return 1;
    return n + sum(n - 1);
}

// Fibonacci series using recursion.
int fibonacci(int n){
    if (n == 0 || n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Checking an array wheather it is sorted or not using recursion.
bool check_sort(std::vector<int> &nums, int n){
    if (n == 0 || n == 1) return true;
    return nums[n - 1] >= nums[n - 2] && check_sort(nums, n - 1);
}

// Recursive Binary Search.
int Recursive_Bin_Seach(std::vector<int> &nums, int tar, int st, int end){
    if (st <= end){
        int mid = st + (end - st) / 2;
        if (nums[mid] == tar){
            return mid;
        }else if (nums[mid] <= tar){
            return Recursive_Bin_Seach(nums, tar, mid + 1, end);
        }else{
            return Recursive_Bin_Seach(nums, tar, st, mid - 1);
        }
    }
    return -1;
}

// Print all subsets
void printSubsets(std::vector<int>& arr, std::vector<int>& ans, int i){
    if (i == arr.size()){

        std::cout<< '{';
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << ans[i];
        }
        std::cout << '}'<< " ";
        return;
    }
    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans,i+1);

    ans.pop_back();
    //exclude
    printSubsets(arr,ans,i+1); 
}

int main(){
    int n = 10;
    // recursion_func(n);

    // std::cout << factorial(n) << std::endl;

    // std::cout << sum(n) << '\n';

    // std::cout << fibonacci(n) << std::endl;

    // std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // std::cout << check_sort(nums, n) << std::endl;

    // int tar = 9;
    // std::cout << Recursive_Bin_Seach(nums, tar, 0, nums.size() - 1);

    std::vector<int> arr{1,2,3};
    std::vector<int> ans;
    
    printSubsets(arr,ans,0);
    std::cout << std::endl;
    return 0;
}