#include<iostream>
#include<unordered_map>
#include<algorithm> // sort(vec.begin(),vec.end())

bool isAnagram(std::string s,std::string t){
    if(s.length() != t.length()) return false;

    std::unordered_map<char,int> m;
    for(char ch:s){
        m[ch]++;
    }
    for(char c:t){
        //first cancel out the value then compare with "0" weather it will give wrong answere.
        if(--m[c] < 0) return false;
    }
    return true;
}

//Another easy way to solve this problem
bool isanagram(std::string s,std::string t){
    if(s.length() != t.length()) return false;

    std::sort(s.begin(),s.end());
    std::sort(t.begin(),t.end());

    return s == t;
}


int main(){
    std::string s{"rat"};
    std::string t{"car"};

    std::cout << isAnagram(s,t) << std::endl;
    std::cout << isanagram(s,t) << std::endl;

    return 0;
}