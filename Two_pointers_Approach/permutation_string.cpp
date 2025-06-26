#include <iostream>
#include <string>

bool isFreqSame(int freq1[], int freq2[]){
    for (int i = 0; i < 26; i++){
        if (freq1[i] != freq2[i]) return false;
    }
    return true;
}

bool CheckiInclusion(std::string s1, std::string s2){
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++){
        freq[s1[i] - 'a']++;
    }
    int windsize = s1.length();

    for (int i = 0; i < s2.length(); i++){
        int windIdx = 0, idx = i;

        int windfreq[26] = {0};

        while (windIdx < windsize && idx < s2.length()){
            windfreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }
        if (isFreqSame(freq, windfreq)) return true;
    }
    return false;
}

int main(){
    std::string s1 = "ab", s2 = "eidbaooo";
    std::cout << CheckiInclusion(s1,s2) << std::endl;
    return 0;
}