/*************************************************************************
	> File Name: CountOfSmallerNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:24:58 2015
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
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        sort(A.begin(), A.end());
        vector<int> ret;
        //if (A.empty()) return ret;
        for (auto iq : queries) {
            ret.push_back(query(A,iq));
        }
        return ret;
    }

    int query(vector<int> &A, int q) {
        int begin = 0, end = A.size()-1;
        while (begin < end) {
            int mid = end - (end-begin >> 1);
            if (A[mid] >= q) end = mid-1;
            else begin = mid;
        }
        if (end >= 0 && end < A.size() && A[end] < q) return end+1;
        return 0;
    }
};

