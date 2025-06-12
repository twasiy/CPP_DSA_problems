#include <iostream>
#include <vector>

////This is Linear search algorithm for searching something in a 2D array/vector.
bool search(std::vector<std::vector<int>> num, int target){
    for (int i = 0; i < num.size(); i++){
        for (int j = 0; j < num[i].size(); j++){
            if (num[i][j] == target) return true;
        }
    }
    return false;
}

////This is helper Binary search in row function for serching in 2D vector;
bool searchInRow(std::vector<std::vector<int>> num, int target, int row){
    int n = num[0].size();
    int st = 0, end = n - 1;
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (target == num[row][mid]){
            return true;
        }else if (target > num[row][mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return false;
}

////This is optimal solution for searching in a 2D array/vector using Binary search;
bool Opt_search(std::vector<std::vector<int>> num, int target){
    int m = num.size(), n = num[0].size(); // BS on tot rows

    int startrow = 0, endrow = m - 1;
    while (startrow <= endrow){
        int midrow = startrow + (endrow - startrow) / 2;
        if (target >= num[midrow][0] && target <= num[midrow][n - 1]){
            return searchInRow(num, target, midrow); // found the row => BS on this row
        }else if (target >= num[midrow][n - 1]){
            startrow = midrow + 1; // down => right
        }else{
            endrow = midrow - 1; // up => left
        }
    }
    return false;
}

////This function works on when every rows are sorted in accending order and every column sorted in accending order.
bool sorted_in_every_rows_col_search(std::vector<std::vector<int>> mat, int target){
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n - 1;
    while (r < m && c >= 0){
        if (target == mat[r][c]){
            return true;
        }else if (target < mat[r][c]){
            c--;
        }else{
            r++;
        }
    }
    return false;
}

int main(){
    std::vector<std::vector<int>> num = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    std::vector<std::vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 2, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    int target = 34;

    std::cout << search(num, target) << std::endl;

    std::cout << Opt_search(num, target) << std::endl;

    std::cout << sorted_in_every_rows_col_search(mat, target) << std::endl;
    return 0;
}