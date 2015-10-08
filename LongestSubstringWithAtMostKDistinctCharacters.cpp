/*************************************************************************
	> File Name: LongestSubstringWithAtMostKDistinctCharacters.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:18:49 2015
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
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        if (k == 0 || s.empty()) return 0;
        int max_len = 0;
        int begin = 0;
        unordered_map<char, int> hashmap;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (hashmap.count(s[i]) == 0) count++;
            hashmap[s[i]]++;
            while (count > k) {
                hashmap[s[begin]]--;
                if (hashmap[s[begin]] == 0) {
                    hashmap.erase(s[begin]);
                    --count;
                }
                ++begin;
            }
            if (count <= k && max_len < i-begin+1) {
                max_len = i-begin+1;
            }
        }
        return max_len;
    }
};
