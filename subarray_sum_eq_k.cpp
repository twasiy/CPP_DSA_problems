#include <iostream>
#include <vector>
#include <unordered_map>

////This is brute force approch for solving this problem.
int subarr_sum(std::vector<int> &arr, int k){
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++){ // starting point{
        int sum = 0;
        for (int j = i; j < n; j++){// ending point{
            sum += arr[j];
            if (sum == k) count++;
        }
    }
    return count;
}

int subarraySum(std::vector<int> &arr, int k){
    int n = arr.size();
    int count = 0;
    std::vector<int> prefixsum(n, 0);

    prefixsum[0] = arr[0];
    for (int i = 1; i < n; i++){
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }

    std::unordered_map<int, int> m;
    for (int j = 0; j < n; j++){
        if (prefixsum[j] == k) count++;
        int val = prefixsum[j] - k;

        if (m.find(val) != m.end()) count += m[val];

        if (m.find(prefixsum[j]) == m.end()) m[prefixsum[j]] = 0;
        m[prefixsum[j]]++;
    }
    return count;
}

int main(){
    std::vector<int> arr = {9, 4, 20, 3, 10, 5};

    int k = 33;
    std::cout << subarr_sum(arr, k) << std::endl;
    return 0;
}