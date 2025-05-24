#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // The container with most water in brute force approch.
    int mxw = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int wt = j - i;
            int ht = min(height[i], height[j]);
            int area = wt * ht;
            mxw = max(mxw, area);
        }
    }
    cout << mxw << endl;

    ////The container with most water in optimal approch (Two pointer approch)
    int lp = 0;
    int rp = height.size();
    int max_water = 0;
    while (lp < rp)
    {
        int wt = rp - lp;
        int ht = min(height[lp], height[rp]);
        int curr_water = wt * ht;
        max_water = max(max_water, curr_water);
        (height[lp] < height[rp]) ? lp++ : rp--;
    }

    return 0;
}