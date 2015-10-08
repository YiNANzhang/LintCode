/*************************************************************************
	> File Name: Median.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:19:50 2015
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
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        //if (n & 0x1) 
        return partion((n-1)/2, nums, 0, n-1);
        //else return (partion((n-1)/2, nums, 0, n-1) + partion(n/2, nums, 0, n-1))/2;
    }
    
    int partion(int k, vector<int>& nums, int start, int end) {
        //if (start == end && k == 1) return 
        int index = start;
        int i = start, j = start+1;
        while (j <= end) {
            if (nums[j] < nums[index]) {
                swap(nums[i+1], nums[j]); 
                ++i;
            }
            ++j;
        }
        swap(nums[index], nums[i]);
        if (k == i) return nums[i];
        else if (k < i) return partion(k, nums, start, i-1);
        else return partion(k, nums, i+1, end);
    }
};
