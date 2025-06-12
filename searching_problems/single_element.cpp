#include <iostream>
#include <vector>

// Brute-force method (linear time)
int singleIndex(std::vector<int> nums){
    if (nums.size() == 1) return 0;

    for (int i = 0; i < nums.size(); i++){
        if ((i == 0 && nums[i] != nums[i + 1]) ||
            (i == nums.size() - 1 && nums[i] != nums[i - 1]) ||
            (i > 0 && i < nums.size() - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1])){
            return i;
        }
    }
    return -1; // fallback if not found
}

// Binary search method (logarithmic time)
int singleNonDuplicateIndex(std::vector<int> &nums){
    if (nums.size() == 1)
        return 0;

    int st = 0, end = nums.size() - 1;

    while (st <= end){
        int mid = st + (end - st) / 2;

        // Edge cases
        if (mid == 0 && nums[mid] != nums[mid + 1]) return mid;
        if (mid == nums.size() - 1 && nums[mid] != nums[mid - 1]) return mid;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return mid;

        // Move search space
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1; // shouldn't reach if input is valid
}

int main()
{
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    std::cout << singleNonDuplicateIndex(nums) << std::endl;
    std::cout << singleIndex(nums) << std::endl;
    return 0;
}
