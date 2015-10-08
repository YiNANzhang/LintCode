/*************************************************************************
	> File Name: LongestIncresingSubsequence.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:09:57 2015
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
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if (nums.empty()) return 0;
        vector<int> lenMinVal;
        lenMinVal.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (lenMinVal.back() <= nums[i]) {
                lenMinVal.push_back(nums[i]);
            } else {
//                auto find = find_if(lenMinVal.rbegin(), lenMinVal.rend(), bind1st(less<int>(), nums[i]));
//                *find = nums[i];
                int index = bSearch(lenMinVal, nums[i]);
                lenMinVal[index] = nums[i];
            }
        }
        return lenMinVal.size();
    }
    
    int bSearch(vector<int> &nums, int pivot) {
        int end = nums.size()-1;
        int start = 0;
        while (start < end) {
            int mid = start + ((end-start)>>1);
            if (nums[mid] <= pivot) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};
