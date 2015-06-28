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
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
		int n = A.size();
		for (int i = 0; i < n; ++i) {
			if (A[i] <=0 || A[i] > n || A[i] == i+1) {
				break;
			}
			swap(A[A[i]-1], A[i]);
		}
		
		int index;
		for (index = 0; index < n; ++index) {
			if (A[index] != index+1) break;
		}    
		return  index+1;  
    }
};


int main() {
	vector<int> A({-1});
	Solution sl;
	cout << sl.firstMissingPositive(A) << endl;
	return 0;
}