#include <iostream>
#include <string>

std::string removeOccurrences(std::string s, std::string part){
    while (s.length() > 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){

    std::string s = "daabcbaabcbc";
    std::string part = "abc";

    std::cout << removeOccurrences(s, part) << std::endl;

    return 0;
}