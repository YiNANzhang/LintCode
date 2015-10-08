/*************************************************************************
	> File Name: NumberOfAirplanesInTheSky.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:17:59 2015
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
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<int> start;
        vector<int> end;
        for (auto ia : airplanes) {
            start.push_back(ia.start);
            end.push_back(ia.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0;
        int count = 0, max_count = 0;
        while (i < start.size()) {
            if (start[i] < end[j]) {
                ++count;
                max_count = max(count, max_count);
                ++i;
            } else {
                --count;
                ++j;
            }
        }
        return max_count;
    }
};

