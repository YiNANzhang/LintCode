/*************************************************************************
	> File Name: LongestCommonPrefix.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:06:58 2015
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
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.empty()) return "";
        string str;
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if(i >= strs[j].size() || strs[j][i] != c) 
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
