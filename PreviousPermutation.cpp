/*************************************************************************
	> File Name: PreviousPermutation.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:07:40 2015
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
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &A) {
        // write your code here
        auto pivot = A.rbegin();
        pivot = next(pivot);
        while (pivot != A.rend() && *pivot <= *(prev(pivot))) pivot = next(pivot);
        if (pivot == A.rend()) {
            reverse(A.rbegin(), A.rend());
            return A;
        }
        auto change = find_if (A.rbegin(), A.rend(), bind1st(greater<int>(), *pivot));
        swap(*change, *pivot);
        reverse(A.rbegin(), pivot);
        return A;
    }
};
