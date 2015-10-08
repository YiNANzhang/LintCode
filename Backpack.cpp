/*************************************************************************
	> File Name: Backpack.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:23:42 2015
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
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int n = A.size();
        bool dp[m+1];
        fill_n(dp, m+1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            //bool dp = dp[]
            for (int j = m; j >= 0; --j) {
                if (j-A[i] >= 0) {
                    dp[j] = dp[j] || dp[j-A[i]];
                }
            }
        }
        
        for (int i = m; i >= 0; --i) {
            if (dp[i]) return i;
        }
        return 0;
    }
};
