/*************************************************************************
	> File Name: MaximumSubarrayII.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:15:21 2015
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> lmax(n, INT_MIN);
        lmax[0] = nums[0];
        vector<int> rmax(n, INT_MIN);
        rmax[n-1] = nums[n-1];
        int curMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curMax = max(nums[i]+curMax, nums[i]);
            lmax[i] = max(curMax, lmax[i-1]);
        }
        
        curMax = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            curMax = max(nums[i]+curMax, nums[i]);
            rmax[i] = max(curMax, rmax[i+1]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n-1; ++i) {
            ans = max(ans, lmax[i]+rmax[i+1]);
        }
        return ans;
    }
};
