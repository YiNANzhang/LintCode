/*************************************************************************
	> File Name: Majority_Number.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:49:44 2015
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
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int times = 0;
        int candidate;
        for (int i = 0; i < nums.size(); ++i) {
            if (times == 0) {
                times++;
                candidate = nums[i];
            } else if (candidate == nums[i]) {
                times++;
            } else 
                times--;
        }
        return times > 0 ? candidate : -1;
    }
};
