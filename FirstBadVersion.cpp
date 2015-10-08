/*************************************************************************
	> File Name: FirstBadVersion.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:58:39 2015
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
/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end-start>>1);
            if (VersionControl::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        if (VersionControl::isBadVersion(start)) return start;
        return -1;
    }
};

