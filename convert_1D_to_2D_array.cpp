#include<iostream>
#include<vector>

std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
    if (m * n != original.size()) {
        return {};
    }
    std::vector<std::vector<int>> reshaped(m, std::vector<int>(n));
    for (int i = 0; i < original.size(); ++i) {
        reshaped[i / n][i % n] = original[i];
    }
    return reshaped;
}

int main(){
    int m{3};
    int n{3};
    std::vector<int> original{1,2,3,4,5,6,7,8,9};

    auto reshaped = construct2DArray(original,m,n);
    for(int i{};i<m;i++){
        for(int j{};j<n;j++){
            std::cout << reshaped[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}