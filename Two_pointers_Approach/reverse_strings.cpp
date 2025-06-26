#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int st = 0, end = s.size()-1;

    while(st < end){
        std::swap(s[st++],s[end--]);
    }
}

int main(){
    std::vector<char> str{'h','e','l','l','o'};
    reverseString(str);
    for(char s:str){
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}