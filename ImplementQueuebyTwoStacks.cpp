/*************************************************************************
	> File Name: ImplementQueuebyTwoStacks.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 10/ 8 16:51:02 2015
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
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        if (top() != -1) {
            int back = top();
            stack2.pop();
            return back;
        } else {
            throw std::string("Empty Stack");
        }
    }

    int top() {
        // write your code here
        if (stack2.empty()) {
            if (stack1.empty()) {
                throw std::string("Stack Empty");
                return -1;
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};
