/*************************************************************************
	> File Name: CompareStrings.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:08:43 2015
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
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_multiset<char> mset;
        for(int i = 0; i < A.size(); ++i) {
            mset.insert(A[i]);
        } 
        for(int j = 0; j < B.size(); ++j) {
            if(mset.find(B[j]) == mset.end())
                return false;
            mset.erase(mset.find(B[j]));
        }
        return true;
    }
};
