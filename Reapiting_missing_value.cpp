#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findMissingAndReapitingValues(std::vector<std::vector<int>> &grid)
{
    std::vector<int> ans;
    std::unordered_set<int> s;
    int a, b;
    int actualsum, expsum;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            actualsum += grid[i][j];
            if (s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expsum = ((grid.size() * grid.size()) * (grid.size() * grid.size() + 1)) / 2;
    b = expsum + a - actualsum;
    ans.push_back(b);

    return ans;
}

int main()
{

    return 0;
}