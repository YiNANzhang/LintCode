/*************************************************************************
	> File Name: SegmentTreeModify.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:56:58 2015
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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == nullptr || index < root->start || index > root->end) return;
        //int start = end = index;
        //int diff;
        vector<SegmentTreeNode *> path;
        query(root, path, index, value);
        for (auto ip : path) {
            ip->max = max(ip->left->max, ip->right->max);
        }
    }
        void query(SegmentTreeNode *root, vector<SegmentTreeNode *> &path, 
                    int index, int value) {
            if (root == nullptr || root->start > index || root->end < index) return;
            if (root->start == index && root->end == index) {
                root->max = value;
                return;
            } else {
                path.insert(path.begin(), root);
                query(root->left, path, index, value);
                query(root->right, path, index, value);
            }        
        }
};

