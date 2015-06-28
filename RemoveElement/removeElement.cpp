#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        //int n = A.size();
        int n = A.size(), count = 0;
        for (int i = n-1; i >= 0; --i) {
            if(A[i] == elem) {
                count++;
                for(int j = i; j < n - count; ++j) {
                    A[i] = A[i+1];
                }
            }
        }
        A.resize(n-count);
        return n-count;
    }
};
int main() {
	vector<int> A({0,4,4,0,4,4,4,0,2});
	int elem = 4;
	Solution sl;
	cout<<sl.removeElement(A, elem);
	return 0;
}