/*************************************************************************
	> File Name: FindPeakElement.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:45:34 2015
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
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if (A.empty()) return -1;
        int i;
        for (i = 1; i < A.size(); ++i) {
            if (A[i] < A[i-1]) break;
        }
        return i-1;
    }
};
