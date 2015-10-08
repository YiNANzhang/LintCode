/*************************************************************************
	> File Name: MaximumSubarrayDifference.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:14:04 2015
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
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> lmax(n, INT_MIN), lmin(n, INT_MAX);
        vector<int> rmax(n, INT_MIN), rmin(n, INT_MAX);
        lmax[0] = lmin[0] = nums[0];
        rmax[n-1] = rmin[n-1] = nums[n-1];
        int curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curMax = max(curMax+nums[i], nums[i]);
            lmax[i] = max(lmax[i-1], curMax);
            curMin = min(curMin+nums[i], nums[i]);
            lmin[i] = min(lmin[i-1], curMin);
        }

        curMax = nums[n-1];
        curMin = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            curMax = max(curMax+nums[i], nums[i]);
            rmax[i] = max(rmax[i+1], curMax);
            curMin = min(curMin+nums[i], nums[i]);
            rmin[i] = min(rmin[i+1], curMin);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int ans1 = i < n-1 ? abs(lmax[i]-rmin[i+1]) : 0;
            int ans2 = i > 0 ? abs(rmax[i]-lmin[i-1]) : 0;
            ans = max(max(ans1, ans2), ans);
        }
        return ans;
    }
};
