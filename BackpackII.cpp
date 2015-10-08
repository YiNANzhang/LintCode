/*************************************************************************
	> File Name: BackpackII.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:00:08 2015
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
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n = A.size();
        int dp[n][m+1];
        fill_n(&dp[0][0], (n)*(m+1), 0);
        for (int i = 0; i <= m; ++i) {
            if (i >= A[0]) dp[0][i] = V[0];
        }
        for (int i = 1; i < n; ++i) {
            //dp[0][A[i]] = V[i];
            for (int j = m; j >= 0; --j) {
	            //dp[i][j] = i==1 ? 0 : dp[i-1][j];
				if (j>=A[i]) 
				dp[i][j] = dp[i-1][j-A[i]]+V[i] > dp[i-1][j] ? dp[i-1][j-A[i]]+V[i] : dp[i-1][j];
				else 
				    dp[i][j] = dp[i-1][j];
            }
        }
        int res = 0;
        for (int i = m; i >= 0; --i) {
            res = max(dp[n-1][i],res);
        }
        return res;
    }
};

