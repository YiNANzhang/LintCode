/*************************************************************************
	> File Name: SegmentTreeBuild.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:57:27 2015
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
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) return NULL;
        // write your code here
        SegmentTreeNode *root;
        if (start == end) return root = new SegmentTreeNode(start, end);
        else {
            root = new SegmentTreeNode(start, end);
            root->left = build(start, (end+start)>>1);
            root->right = build(((start+end)>>1)+1, end);
        }
        return root;
    }
};
