#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

//Solving this problem using "unordered_map";
bool containsDuplicate_map(std::vector<int>& nums){
    std::unordered_map<int,bool> m;
    for(auto val:nums){
        if(m.find(val) != m.end()) return true;
        m[val] = true;
    }
    return false;
}

//Solving this problem using "unrodered_set";
bool containsDuplicate_set(std::vector<int>& nums){
    std::unordered_set<int> s;
    for(auto val:nums){
        if(s.find(val) != s.end()) return true;
        s.insert(val);
    }
    return false;
}

//Solving this problem using "unrodered_set" with one optimization;
bool containsDuplicate_set_opt(std::vector<int>& nums){
    std::unordered_set<int> s;
    s.reserve(nums.size());

    for (int val : nums) {
        if (s.find(val) != s.end()) return true;
        s.insert(val);
    }
    return false;

}

int main(){

    std::vector<int> nums{1,2,3,1};

    std::cout << containsDuplicate_map(nums) << std::endl;
    std::cout << containsDuplicate_set(nums) << std::endl;
    std::cout << containsDuplicate_set_opt(nums) << std::endl;

    return 0;
}