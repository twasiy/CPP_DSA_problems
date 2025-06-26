#include <iostream>
#include <string>
#include <algorithm>

////This is the main logic behind the reverse the words in a string.It is not optimized for large datasets and time complexity.
std::string reverse_words(std::string s){
    std::string ans = "";
    std::reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++){
        std::string word = "";
        while (i < s.length() && s[i] != ' '){
            word += s[i];
            i++;
        }
        std::reverse(word.begin(), word.end());
        if (word.length() > 0) ans += " " + word;
    }
    return ans.substr(1);
}

//// This version is more optimized and more suitable for large dataset and the time complexity is O(n) it executes in 0ms.
std::string reverseWords(std::string s){
    std::reverse(s.begin(), s.end()); // Step 1: Reverse the whole string
    std::string ans = "", word = "";

    for (char c : s){
        if (c != ' '){
            word += c; // Build the word
        }else if (!word.empty()){
            reverse(word.begin(), word.end()); // Fix the word
            if (!ans.empty())
                ans += ' ';
            ans += word;
            word.clear(); // Reset for next word
        }
    }

    // Handle the last word (if any)
    if (!word.empty()){
        reverse(word.begin(), word.end());
        if (!ans.empty()) ans += ' ';
        ans += word;
    }
    return ans;
}

int main(){
    std::string s = " hello world       hi my name is wasiy     ";

    std::cout << reverseWords(s) << std::endl;  // working with complex dataset
    std::cout << reverse_words(s) << std::endl; // Best for clean and logic building
    return 0;
}