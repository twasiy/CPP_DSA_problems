#include <iostream>
#include <vector>

int string_compression(std::vector<char> &chars){
    int idx = 0;
    for (int i = 0; i < chars.size(); i++){
        char ch = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == ch){
            count++;i++;
        }
        if (count == 1){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            std::string str = std::to_string(count);
            for (char dig : str){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}

int main(){
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    return 0;
}