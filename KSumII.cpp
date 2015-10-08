/*************************************************************************
	> File Name: KSumII.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:00:58 2015
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
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > ret;
        vector<int> path;
        sort(A.begin(), A.end());
        dfs(ret, path, k, target, A, 0);
        return ret;
    }
    
    bool dfs(vector<vector<int>> &ret, vector<int> &path, int k, int target, vector<int> &A, int start) {
        if (target == 0 && k == 0) {
            ret.push_back(path);
            return false;
        }
        if (target < 0 || k < 0) {
            return false;
        }
        for (int i = start; i < A.size(); ++i) {
            path.push_back(A[i]);
            dfs(ret, path, k-1, target-A[i], A, i+1);
            path.pop_back();
        }
        return false;
    }
};

