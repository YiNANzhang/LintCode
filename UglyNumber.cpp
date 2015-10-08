/*************************************************************************
	> File Name: UglyNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:23:59 2015
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
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        long long ret = 0;
        vector<long long> uglyNum;
        long long prime3;
        long long prime5;
        long long prime7;
        uglyNum.push_back(1);
        prime3 = prime5 = prime7 = 0;
        for (int i = 0; i < k; ++i) {
            long long cur = uglyNum.back();
            while(uglyNum[prime3]*3 <= cur) prime3++;
            while(uglyNum[prime5]*5 <= cur) prime5++;
            while(uglyNum[prime7]*7 <= cur) prime7++;
            cur = min(uglyNum[prime3]*3, min(uglyNum[prime5]*5, uglyNum[prime7]*7));
            uglyNum.push_back(cur);
        }
        return uglyNum.back();
    }
};
