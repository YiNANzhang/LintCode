/*************************************************************************
	> File Name: SegmentTreeQuery.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:58:01 2015
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
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr || start > end) return INT_MIN;
        if (start <= root->start && end >= root->end) {
            return root->max;
        }
        int l = root->start + (root->end - root->start >> 1);
        int r = l+1;
        if (start >= r) {
            return query(root->right, start, end);
        } else if (end <= l) {
            return query(root->left, start, end);
        } else {
            return max(query(root->left, start, l), query(root->right, r, end));
        }
        
    }
};

