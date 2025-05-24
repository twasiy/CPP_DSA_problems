#include <iostream>
#include <unordered_set>
#include <vector>

////This is straight forward approch when you don't have any condition.
int findDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> s;

    for (int val : nums)
    {
        if (s.find(val) != s.end())
        {
            return val;
        }
        s.insert(val);
    }
    return -1;
}

/*This optimized space complexity approch when you have condition that you can't use any extra data structures for solving the problem;*/

////This is called slow fast pointer approch. This give us approximately 4ms in leetcode.
int duplicate(std::vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];       //+1
        fast = nums[nums[fast]]; //+2
    } while (slow != fast);
    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow]; //+1
        fast = nums[fast]; //+1
    }
    return slow;
}

////We can also write the code like this in "for(;;)" loop structure. This give us 0ms time in leetcode
int findDuplicate_optimal(std::vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];

    // Phase 1: Detect intersection point in the cycle
    for (;;)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }

    // Phase 2: Find the entrance to the cycle (duplicate number)
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    std::vector<int> num = {1, 2, 3, 4, 6, 7, 8, 9, 9};

    std::cout << findDuplicate(num) << std::endl;

    return 0;
}