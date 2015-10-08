/*************************************************************************
	> File Name: LongestWords.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:52:10 2015
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
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        unordered_map<int, vector<string>> lengthMap;
        int maxLength = 0;
        int size = 0;
        for(int i = 0; i < dictionary.size(); ++i) {
            size = dictionary[i].size();
            lengthMap[size].push_back(dictionary[i]);
            maxLength = maxLength < size ? size : maxLength; 
        }
        vector<string> res;
        for (auto it : lengthMap[maxLength]) {
            res.push_back(it);
        }
        return res;
    }
};
