#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

////This is the main logic behind the reverse the words in a string.It is not optimized for large datasets and time complexity.
string reverse_words(string s)
{
    string ans = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (i < s.length() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

//// This version is more optimized and more suitable for large dataset and the time complexity is O(n) it executes in 0ms.
string reverseWords(string s)
{
    reverse(s.begin(), s.end()); // Step 1: Reverse the whole string
    string ans = "", word = "";

    for (char c : s)
    {
        if (c != ' ')
        {
            word += c; // Build the word
        }
        else if (!word.empty())
        {
            reverse(word.begin(), word.end()); // Fix the word
            if (!ans.empty())
                ans += ' ';
            ans += word;
            word.clear(); // Reset for next word
        }
    }

    // Handle the last word (if any)
    if (!word.empty())
    {
        reverse(word.begin(), word.end());
        if (!ans.empty())
            ans += ' ';
        ans += word;
    }

    return ans;
}

int main()
{
    string s = " hello world       hi my name is wasiy     ";

    cout << reverseWords(s) << endl;  // working with complex dataset
    cout << reverse_words(s) << endl; // Best for clean and logic building

    return 0;
}