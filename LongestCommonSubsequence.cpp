/*************************************************************************
	> File Name: LongestCommonSubsequence.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:52:47 2015
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
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int n = A.size();
        int m = B.size();
        //int l = min(m, n);
        int dp[m+1];
        fill_n(dp, m+1, 0);
        for (int i = 1; i <= n; ++i) {
            int prv = dp[0];
            for (int j = 1; j <= m; ++j) {
                int upper = dp[j];
                if (A[i-1] == B[j-1]) dp[j] = prv+1;
                else dp[j] = max(dp[j], dp[j-1]);
                prv = upper;
            }
        }
        return dp[m];
    }
};
