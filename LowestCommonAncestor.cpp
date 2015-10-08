/*************************************************************************
	> File Name: LowestCommonAncestor.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:03:54 2015
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (root == A || root == B) return root;
        vector<TreeNode*> patha;
        vector<TreeNode*> pathb;
        genPath(root, A, patha);
        genPath(root, B, pathb);
        TreeNode *last;
        for (int i = 0; i < patha.size() && i < pathb.size(); ++i) {
            if (patha[i] == pathb[i]) last = patha[i];
        }
        return last;
    }
    
    bool genPath(TreeNode *root, TreeNode *A, vector<TreeNode*> &patha) {
        if (root == A) {
            patha.push_back(A); return true;
        }
        if (root == NULL) return false;
        
        patha.push_back(root);
        if (genPath(root->left, A, patha) || genPath(root->right, A, patha))
            return true;
        patha.pop_back();
        return false;
    }
};

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (root == A || root == B) return root;
        if (root == NULL) return NULL;
        TreeNode *left = lowestCommonAncestor(root->left, A, B);
        TreeNode *right = lowestCommonAncestor(root->right, A, B);
        if (left != NULL && right != NULL) return root;
        return left == NULL ? right : left;
    }
};
