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
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int> > result;
		for (int f = 0; f < n; ++f) {
			if (f > 0 && nums[f] == nums[f-1]) continue;
			for (int s = f+1; s < n; ++s) {
				if (s != f+1 && nums[s] == nums[s-1]) continue;
				for (int t = n-1; t > s; --t) {
					if (t != n-1 && nums[t] == nums[t+1]) continue;
					if (nums[f] + nums[s] + nums[t] == 0) {
						result.push_back(vector<int>({nums[f], nums[s], nums[t]}));
					} else if (nums[f] + nums[s] + nums[t] < 0) {
						break;
					}
				}
			}
		}
		return result;
    }
};





int main() {
	vector<int> nums({-1,0,1,2,-1,4});
	Solution sl;
	vector<vector<int> > result = sl.threeSum(nums);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}