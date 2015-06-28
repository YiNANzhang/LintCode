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
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result;
        int n = nums.size();
        long long bdp[n];
        long long fdp[n];
        bdp[0] = 1; 
        fdp[n-1] = 1;
        for (int i = 1; i <= n-1; ++i) bdp[i] = bdp[i-1] * nums[i-1];
        for (int j = n-2; j >= 0; --j) fdp[j] = fdp[j+1] * nums[j+1];
        for (int i = 0; i < n; ++i) {
            result.push_back(bdp[i]*fdp[i]);
        }
        return result;   
    }
};
int main() {
	vector<int> nums({1,2,3});
	Solution sl;
	vector<long long > result = sl.productExcludeItself(nums);
	for(int i = 0; i < result.size(); ++i)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}