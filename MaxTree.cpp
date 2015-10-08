/*************************************************************************
	> File Name: MaxTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:06:19 2015
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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        TreeNode *root;
        if (A.empty()) return root;
        root = new TreeNode(A[0]);
        for (int i = 1; i < A.size(); ++i) {
            TreeNode *cur = new TreeNode(A[i]);
            if (cur->val > root->val) {
                cur->left = root;
                root = cur;
            } else {
                TreeNode *insert = root;
                while (insert->right != NULL && insert->right->val > cur->val) {
                    insert = insert->right;
                }
                cur->left = insert->right;
                insert->right = cur;
            } 
        }
        return root;
    }
};
