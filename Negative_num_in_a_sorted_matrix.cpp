#include<iostream>
#include<vector>

int countNegatives(std::vector<std::vector<int>>& grid) {
    int count = 0;
    for(int i = 0;i<grid.size();i++){
        int st = 0;
        int end = grid[i].size() -1;
        int firstNegativeIndex = grid[i].size(); // If no negative found, all are non-negative
         // Binary search to find first negative number in decreasing array
        while(st<=end){
            int mid = st + (end-st)/2;
            if(grid[i][mid]<0){
                firstNegativeIndex = mid;
                end = mid-1; // Look for earlier occurrence of negative (moving left)
            }else{
                st = mid+1; // Current element is non-negative, negatives are to the right
            }
        }
        // Count negatives from first negative position to end
        count += grid[i].size() - firstNegativeIndex;
    }
    return count;
}

int main(){

    std::vector<std::vector<int>> grid{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    int value = countNegatives(grid);
    std::cout << value << std::endl;

    return 0;
}