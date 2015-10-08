/*************************************************************************
	> File Name: MaximumSubarray.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:55:26 2015
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
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.empty()) return 0;
        int res = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                sum = nums[0];
            } else {
                sum = nums[i] > (sum+nums[i]) ? nums[i] : (sum+nums[i]);
            }
            res = max(res, sum);
        }
        return res;
    }
};
