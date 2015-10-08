/*************************************************************************
	> File Name: Rehashing.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 17:12:58 2015
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
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode*> rhash;
        int size = hashTable.size();
        rhash.resize(2*size);
        for (auto it : hashTable) {
            while (it) {
                rhash[hashcode(it->val, 2*size)] = new ListNode(it->val);
                it = it->next;
            }
        }
    }
};

