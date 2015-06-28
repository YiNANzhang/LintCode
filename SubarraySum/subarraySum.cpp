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
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> result;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if(sum == 0) {
                    result = vector<int>({i,j});
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
	vector<int> nums({-5,10,5,-3,1,1,1,-2,3,-4});
	Solution sl;
	vector<int> result=sl.subarraySum(nums);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}