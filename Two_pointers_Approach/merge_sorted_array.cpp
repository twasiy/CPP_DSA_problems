#include <iostream>
#include <vector>

void merge(std::vector<int> &A, int m, std::vector<int> &B, int n){
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0){
        if (A[i] >= B[j]){
            A[idx--] = A[i--]; // first add the highest value then reduce the idx and i value;
        }else{
            A[idx--] = B[j--]; // fist add the highest value then reduce the idx and j value;
        }
    }
    while (j >= 0){
        A[idx--] = B[j--]; // fist add the highest value then reduce the idx and j value;
    }
}

int main(){
    std::vector<int> A{1, 2, 3, 0, 0, 0};
    std::vector<int> B{2, 5, 6};

    int m{3}; // number of valid elements in A
    int n = B.size();

    merge(A, m, B, n);

    for (int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
