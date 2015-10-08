#include<iostream>
#include<>

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if (nums.empty()) return 0;
        int maxPrd = nums[0];
        int curPos = nums[0] > 0 ? nums[0] : 1;
        int curNeg = nums[0] < 0 ? nums[0] : 1;
        //int cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            //cur *= nums[i];
            curPos *= nums[i];
            curNeg *= nums[i];
            maxPrd = max(maxPrd, max(curPos, curNeg));
            curNeg = min(curPos, curNeg) < 0 ? min(curPos, curNeg) : 1;
            curPos = max(curPos, curNeg) > 0 ? max(curPos, curNeg) : 1;
        }
        return maxPrd;
    }
};
