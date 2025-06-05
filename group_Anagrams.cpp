#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

std::vector<std::vector<std::string>> Group_Anagrams(std::vector<std::string> strs){
    std::unordered_map<std::string,std::vector<std::string>> m;

    for(std::string& str:strs){
        std::string key{str};
        std::sort(key.begin(),key.end());
        m[key].push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for(auto& pair : m){
        result.push_back(pair.second);
    }
    return result;
}


int main(){

    std::vector<std::string> strs{"eat","tea","tan","ate","nat","bat"};

    std::vector<std::vector<std::string>> result = Group_Anagrams(strs);
    for (const auto& group : result) {
        std::cout << "[ ";
        for (const auto& word : group) {
            std::cout << "\"" << word << "\" ";
        }
        std::cout << "]\n";
    }

    return 0;
}