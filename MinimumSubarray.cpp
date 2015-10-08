/*************************************************************************
	> File Name: MinimumSubarray.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:51:32 2015
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
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (nums.empty()) return 0;
        int sum = nums[0];
        int res = sum;
        for (int i = 1; i < nums.size(); ++i) {
            sum = nums[i] < (sum + nums[i]) ? nums[i] : (sum + nums[i]);
            res = min(res, sum);
        }
        return res;
    }
};
