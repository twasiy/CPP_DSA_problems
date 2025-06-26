#include <iostream>

// The API isBadVersion is defined for you in the leetcode but now avoiding error I have made a dummy function that will not work.
// bool isBadVersion(int version);
bool isBadVersion(int version);

int firstBadVersion(int n){
    int st = 0, end = n;
    int result;
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (isBadVersion(mid) == true){
            end = mid - 1;
            result = mid;
        }else{
            st = mid + 1;
        }
    }
    return result;
}

int main(){
    

    return 0;
}