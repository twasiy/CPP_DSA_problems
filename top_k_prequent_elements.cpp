#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

//option 1: Using a Min-Heap (priority_queue) O(n log k)
std::vector<int> topKFrequent1(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums) {
        freq[num]++;
    }
    // Min-heap to keep top k elements
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    // Collect results
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

// option 2: Bucket Sort (Faster, O(n))
std::vector<int> topKFrequent2(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    // Create buckets where index = frequency
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }

    // Collect top k frequent elements
    std::vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }
    return result;
}

//But this is simple and readable.It also takes O(n long n)
std::vector<int> topKFrequent3(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<std::pair<int, int>> pairs;
        std::vector<int> res;

        for (int i : nums) {
            freq[i]++;
        }
        for (const std::pair<int, int>& ele : freq) {
            pairs.push_back(std::make_pair(ele.second, ele.first)); // swap so that frequence comes first
        }

        std::sort(pairs.begin(), pairs.end());
        for (int i = 1; i < k + 1; ++i) {
            res.push_back(pairs[pairs.size() - i].second);
        }
        return res;
    }

int main(){

    std::vector<int> nums{1,1,1,2,2,3};
    int k = 2;

    auto result1 = topKFrequent1(nums,k);
    auto result2 = topKFrequent2(nums,k);
    auto result3 = topKFrequent3(nums,k);

    for(int res:result1){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    for(int res:result2){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    for(int res:result3){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}