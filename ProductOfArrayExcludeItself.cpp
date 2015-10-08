/*************************************************************************
	> File Name: ProductOfArrayExcludeItself.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:11:04 2015
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
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result;
        int n = nums.size();
        long long bdp[n];
        long long fdp[n];
        bdp[0] = 1; 
        fdp[n-1] = 1;
        for (int i = 1; i <= n-1; ++i) bdp[i] = bdp[i-1] * nums[i-1];
        for (int j = n-2; j >= 0; --j) fdp[j] = fdp[j+1] * nums[j+1];
        for (int i = 0; i < n; ++i) {
            result.push_back(bdp[i]*fdp[i]);
        }
        return result;   
    }
};
