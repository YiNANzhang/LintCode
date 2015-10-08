/*************************************************************************
	> File Name: IntervalMinimumNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:16:08 2015
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
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    struct SegmentTree {
        int start, end, min;
        SegmentTree *left, *right;
        SegmentTree(int start, int end, int min):start(start), end(end), min(min) {
            left = right = NULL;
        }
    };
    
    void SegmentTreeBuild(vector<int> &A, int start, int end, SegmentTree *&root) {
        if (start > end) return;
        root = new SegmentTree(start, end, INT_MAX);
        if (start == end) {
            root->min = A[start];
        } else {
            int mid = start + (end-start>>1);
            SegmentTreeBuild(A, start, mid, root->left);
            SegmentTreeBuild(A, mid+1, end, root->right);
            int l = root->left == NULL ? INT_MAX : root->left->min;
            int r = root->right == NULL ? INT_MAX : root->right->min;
            root->min = min(l, r);
        }
    }

    int SegmentTreeQuery(SegmentTree *&root, Interval q) {
        if (root == NULL || q.start > root->end || q.end < root->start || q.start > q.end) return INT_MAX;
        if (q.start <= root->start && q.end >= root->end) return root->min;
        int l = INT_MAX;
        int r = INT_MAX;
        if (root->left) {
            Interval il(max(root->left->start, q.start), min(root->left->end, q.end));
            l = SegmentTreeQuery(root->left, il);
        }
        if (root->right) {
            Interval ir(max(root->right->start, q.start), min(root->right->end, q.end));
            r = SegmentTreeQuery(root->right, ir);
        }
        //Interval l(max(root->, q.start), min(root->end, q.end));
        return min(l, r);
    }

    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTree *root;
        SegmentTreeBuild(A, 0, A.size()-1, root);
        vector<int> ret;
        for (auto iq : queries) {
            int val = SegmentTreeQuery(root, iq);
            ret.push_back(val);
        }
        return ret;
    }
};

