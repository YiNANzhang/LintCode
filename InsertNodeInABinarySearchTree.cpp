/*************************************************************************
	> File Name: InsertNodeInABinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:47:00 2015
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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == NULL) return node;
        if (node == NULL) return root;
        TreeNode *insrtNode = root;
        while (insrtNode) {
            if (node->val <= insrtNode->val) {
                if (insrtNode->left == NULL) {
                    insrtNode->left = node;
                    break;
                } else {
                    insrtNode = insrtNode->left;
                }
            } else {
                if (insrtNode->right == NULL) {
                    insrtNode->right = node;
                    break;
                } else {
                    insrtNode = insrtNode->right;
                }
            }
        }
        return root;
    }
};
