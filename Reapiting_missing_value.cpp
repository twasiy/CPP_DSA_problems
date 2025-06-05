#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findMissingAndReapitingValues(std::vector<std::vector<int>> &grid){
    std::vector<int> ans;
    std::unordered_set<int> s;
    int a, b , n = grid.size();
    int actualsum, expsum;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < grid.size(); j++){
            actualsum += grid[i][j];
            if (s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expsum = ((n * n) * (n * n + 1)) / 2;
    b = expsum + a - actualsum;
    ans.push_back(b);

    return ans;
}

int main()
{
    std::vector<std::vector<int>> grid{{1,2,3,4,5,6,7,8,9},{3,5,7,9,1}};
    auto result = findMissingAndReapitingValues(grid);
    for(auto i : result){
        std::cout<< i << " ";
    }
    std::cout <<'\n';

    return 0;
}