#include<iostream>
#include<vector>
#include<algorithm>

int binary_search(std::vector<std::pair<std::pair<int,int>,int>>& sorted,int x){
    int n = sorted.size();
    if(sorted[n-1].first.first < x) return -1;
    int st = 0,end = n-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(sorted[mid].first.first >= x){
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return sorted[st].second;
}

std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals){
    std::vector<std::pair<std::pair<int,int>,int>> sorted;
    int n = intervals.size();
    for(int i = 0;i<n;i++){
        sorted.push_back({{intervals[i][0],intervals[i][1]},i});
    }
    std::sort(sorted.begin(),sorted.end());

    std::vector<int> result(n,-1);
    for(int i = 0;i<n;i++){
        result[i] = binary_search(sorted,intervals[i][1]);
    }
    return result;
}

int main(){
    std::vector<std::vector<int>> intervals{{3,4},{2,3},{1,2}};

    auto result = findRightInterval(intervals);
    for(auto res:result){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}