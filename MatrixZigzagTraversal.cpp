/*************************************************************************
	> File Name: MatrixZigzagTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:19:32 2015
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
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> res;
        if (matrix.empty()) return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        //int i = 0, j = 0;
        bool flag = false;
        int r = 0, c = 0;
        for (int i = 0; i < rows+cols-1 /*&& r >= 0 && r < rows && c >= 0 && c < cols*/; ++i) {
            if (!flag) {
                while (r > 0 && c < cols-1) res.push_back(matrix[r--][c++]);
                res.push_back(matrix[r][c]);
                flag = !flag;
                if (c < cols-1) c++;
                else r++;
            } else {
                while (r < rows-1 && c > 0) res.push_back(matrix[r++][c--]);
                res.push_back(matrix[r][c]);
                flag = !flag;
                if (r < rows-1) r++;
                else c++;
            }
        }
        return res;
    }
};
