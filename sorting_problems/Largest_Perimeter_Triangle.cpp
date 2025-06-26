#include <iostream>
#include <vector>
#include <chrono>
#include <thread> //for multithreading (std::tread)

int pivot(std::vector<int>& nums, int st, int end){
    int i = st, pivotValue = nums[end];
    for (int j = st; j <= end - 1; j++) {
        if (nums[j] >= pivotValue){
            std::swap(nums[j], nums[i]);
            i++;
        }
    }
    std::swap(nums[end], nums[i]);
    return i;
}

void sort(std::vector<int>& nums, int st, int end, int depth = 0){
    if (st < end) {
        int pivotIndex = pivot(nums, st, end);

        // Set a threshold to avoid too many threads
        if (depth < 4) {  // You can tune this depth
            std::thread leftThread(sort, std::ref(nums), st, pivotIndex - 1, depth + 1);
            std::thread rightThread(sort, std::ref(nums), pivotIndex + 1, end, depth + 1);
            leftThread.join();
            rightThread.join();
        } else {
            sort(nums, st, pivotIndex - 1, depth);
            sort(nums, pivotIndex + 1, end, depth);
        }
    }
}

// Greedy approach (optimal)
int largestPerimeter(std::vector<int>& nums){
    int n = nums.size();
    sort(nums, 0, n - 1);
    
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] < nums[i + 1] + nums[i + 2]) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}

int main(){
    std::vector<int> arr(100000000);
    for (int i = 0; i < 100000000; i++){
        arr[i] = std::rand() % 100000000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    int value = largestPerimeter(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Optimal result: " << value << std::endl;
    std::cout << "Time taken: " << duration.count() << "ms" << std::endl;

    return 0;
}

