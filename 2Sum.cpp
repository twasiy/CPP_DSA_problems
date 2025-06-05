#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

////This is my Twosum function that works very well.This is called two pointer approch.
std::vector<int> Twosum(std::vector<int> num, int target){
    int start = 0, end = num.size() - 1;
    std::sort(num.begin(), num.end());
    std::vector<int> ans;

    while (start < end){
        int sum = num[start] + num[end];
        if (sum == target){
            ans.push_back(num[start]);
            ans.push_back(num[end]);
            break;
        }else if (sum < target){
            start++;
        }else{
            end--;
        }
    }
    return ans;
}

//// This is the Twosum function that is most optimized way to solve the problem.This is called hashing.
std::vector<int> Twosum_opt(std::vector<int> &arr, int target){
    std::unordered_map<int, int> m;
    std::vector<int> ans;

    for (int i = 0; i < arr.size(); i++){
        int sec = target - arr[i];

        if (m.find(sec) != m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[arr[i]] = i;
    }
    return ans;
}

////This is the updated version of (Twosum_upt) function that allows user to calculate this even more faster
std::vector<int> Twosum_upt(std::vector<int> &arr, int target){
    std::unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++){
        int sec = target - arr[i];
        if (m.count(sec)){
            return {m[sec], i};
        }
        m[arr[i]] = i;
    }
    return {};
}

int main(){

    std::vector<int> num = {1, 2, 3, 4, 5, 6};
    int target = 9;

    std::vector<int> result = Twosum_opt(num, target);

    for (int value : result){
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}