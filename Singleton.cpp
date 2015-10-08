/*************************************************************************
	> File Name: Singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:59:11 2015
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
    static Solution* sg;
    Solution() {
        
    }
public:
    /**
     * @return: The same instance of this class every time
     */
     
    static Solution* getInstance() {
        // write your code here
        static Solution* sg;
        if (!sg) {
            sg = new Solution();
        }
        return sg;
    }
};
