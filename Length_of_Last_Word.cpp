#include<iostream>
#include<string>

int lengthOfLastWord(std::string s){
    int length = 0;
    int i = s.length() - 1;
    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;
    // Count characters until next space or start of string
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    return length;
}

int main(){
    
    std::string s1 = "Hello World";
    std::string s2 = "   fly me   to   the moon  ";
    std::string s3 = "luffy is still joyboy";

    std::cout << "The length of the last word of s1 is: " << lengthOfLastWord(s1) << std::endl;
    std::cout << "The length of the last word of s2 is: " << lengthOfLastWord(s2) << std::endl;
    std::cout << "The length of the last word of s3 is: " << lengthOfLastWord(s3) << std::endl;
    
    return 0;
}