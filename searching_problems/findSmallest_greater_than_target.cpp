#include<iostream>
#include<vector>

char nextGreatestLetter(std::vector<char>& letters, char target) {
    int st = 0, end = letters.size() - 1;

    while(st <= end) {
        int mid = st + (end - st) / 2;
    
        if(letters[mid] > target) {
            end = mid - 1;
        } else {  // letters[mid] <= target
            st = mid + 1;
        }
    }
    return letters[st % letters.size()];
}

int main(){
    std::vector<char> letters{'a','c','g','i','p','q','w','x','z'};

    char target{'q'};
    std::cout << nextGreatestLetter(letters,target) << std::endl;

    return 0;
}