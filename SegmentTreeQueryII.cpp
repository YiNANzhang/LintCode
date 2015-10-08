/*************************************************************************
	> File Name: SegmentTreeQueryII.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:04:43 2015
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
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr || start > end) return 0;
        if (root->start == start && root->end == end) return root->count;
        int l = root->start + (root->end - root->start >> 1);
        return query(root->left, max(root->start, start), min(l, end)) + query(root->right, max(l+1, start), min(root->end, end));
    }
};

