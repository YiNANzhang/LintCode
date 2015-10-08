/*************************************************************************
	> File Name: SortLettersByCase.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:54:41 2015
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
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int lowend = -1, j = 0;
        while (j < letters.size()) {
            if (letters[j] >= 'a' && letters[j] <= 'z') {
                swap(letters[lowend+1], letters[j]);
                ++lowend;
            }
            ++j;
        }
    }
};
