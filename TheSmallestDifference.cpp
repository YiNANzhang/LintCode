/*************************************************************************
	> File Name: TheSmallestDifference.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:56:12 2015
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
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int minDif = INT_MAX;
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            minDif = min(minDif, abs(A[i]-B[j]));
            if (A[i] == B[j]) break;
            else if (A[i] > B[j]) ++j;
            else ++i;
        }
        return minDif;
    }
};
