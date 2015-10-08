/*************************************************************************
	> File Name: MajorityNumberII.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:08:04 2015
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
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return -1;
        if (nums.size() < 3) return nums[0];
        int times[2] = {0, 0};
        int candidates[2];
        for (int i = 0; i < nums.size(); ++i) {
            if (times[0] == 0 && times[1] == 0) {
                candidates[0] = nums[i];
                times[0]++;
            } else if (times[0] == 0) {
                if (candidates[1] == nums[i]) {
                    times[1]++;
                } else {
                    candidates[0] = nums[i];
                    times[0]++;
                }
            } else if (times[1] == 0) {
                if (candidates[0] == nums[i]) {
                    times[0]++;
                } else {
                    candidates[1] = nums[i];
                    times[1]++;
                }
            } else {
                if (nums[i] == candidates[0]) {
                    times[0]++;
                } else if (nums[i] == candidates[1]) {
                    times[1]++;
                } else {
                    times[0]--;
                    times[1]--;
                }
            }
        }
        
        int count = 0;
        if (times[0] > 0) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == candidates[0]) count++;
                if (count > nums.size()/3) return candidates[0];
            }
        }
        
        count = 0;
        if (times[1] > 0) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == candidates[1]) count++;
                if (count > nums.size()/3) return candidates[1];
            }
        }
        
        return -1;
        
    }
};
