/*************************************************************************
	> File Name: IntervalSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:12:29 2015
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
    struct SegmentTree {
        int start;
        int end;
        long long sum;
        SegmentTree *left, *right;
        SegmentTree(int start0, int end0, int sum0) {
            this->start = start0;
            this->end = end0;
            this->sum = sum0;
            this->left = this->right = NULL;
        }
    };
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTree *root;
        vector<long long> ans;
        root = buildSegmentTree(A, 0, A.size()-1);
        for (auto q : queries) {
            long long ret = querySegmentTree(root, q);
            ans.push_back(ret);
        }
        return ans;
    }
    
    SegmentTree *buildSegmentTree(vector<int> &A, int start, int end) {
        if (start > end) return nullptr;
        SegmentTree *root = new SegmentTree(start, end, 0);
        long long sum;
        if (start == end) {
            sum = A[start];
        } else {
            int l = start + (end-start>>1);
            root->left = buildSegmentTree(A, start, l);
            root->right = buildSegmentTree(A, l+1, end);
            long long LeftSum = root->left == nullptr ? 0 : root->left->sum;
            long long RightSum = root->right == nullptr ? 0 : root->right->sum; 
            sum = LeftSum + RightSum;
        }
        root->sum = sum;
        return root;
    }
    
    long long querySegmentTree(SegmentTree *&root, Interval q) {
        if (root == nullptr) return 0;
        if (q.end < root->start || q.start > root->end || q.start > q.end) return 0;
        if (q.start == root->start && q.end == root->end) return root->sum;
        Interval l(max(root->start, q.start), min(root->start + (root->end-root->start >> 1), q.end));
        Interval r(max(root->start + (root->end-root->start >> 1)+1, q.start),
        min(q.end, root->end));
        //l.start = max(root->start, q.start);
        //l.end = min(root->start + (root->end-root->start >> 1), q.end);
        //r.start = max(root->start + (root->end-root->start >> 1)+1, q.start);
        //r.end = min(q.end, end);
        return querySegmentTree(root->left, l)+querySegmentTree(root->right, r);
    }
};
