#include <iostream>
#include <string>

bool palindrome(std::string s){
    int st = 0, end = s.length() - 1;
    while (st < end){
        if (tolower(s[st]) != tolower(s[end])){
            return false;
        }else{
            st++;end--;
        }
    }
    return true;
}

bool isAlphaNum(char ch){
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) return true;
    return false;
}

bool isPalindrome(std::string s){
    int st = 0, end = s.length() - 1;
    while (st < end){
        if (isAlphaNum(s[st]) != true){
            st++;
            continue;
        }
        if (isAlphaNum(s[end]) != true){
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end])){
            return false;
        }else{
            st++;end--;
        }
    }
    return true;
}

int main(){
    std::string s = "Ac3?e3c&a";
    std::cout << isPalindrome(s) << std::endl;
    return 0;
}