/*
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using std::cout;
using std::vector;
using std::map;
using std::pair;
using std::min;

int main()
{
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    
    int i, i1, i2, area, max_area;
    int n = input.size();
    map<int,pair<int,int>> omap;
    i1 = 0;
    i2 = n-1;
    max_area = 0;
    while (i1 < i2) {
        area = min(input[i1],input[i2]) * (i2-i1);
        if (area > max_area)
            max_area = area;
        omap[area] = pair(i1,i2);
        if (input[i1] < input[i2])
            i1 += 1;
        else
            i2 -= 1;
    }

    cout << max_area << " : (" << omap[max_area].first
         << "," << omap[max_area].second << ")\n";
}
