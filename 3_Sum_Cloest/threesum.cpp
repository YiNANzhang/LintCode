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
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
		int gap = INT_MAX;
		int result = 0;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int f = 0; f < n; ++f) {
			if (f > 0 && nums[f] == nums[f-1]) continue;
			for (int s = f+1; s < n; ++s) {
				if (s != f+1 && nums[s] == nums[s-1]) continue;
				for (int t = n-1; t > s; --t) {
					if (t != n-1 && nums[t] == nums[t+1]) continue;
					int sum = nums[f]+nums[s]+nums[t];
					if (gap > abs(target-sum)) {
						gap = abs(target-sum);
						result = sum;
					}
					if (sum < target) {
						break;
					}
				}
			}
		}
		return result;
    }
};

int main() {
	vector<int> nums({1,0,-1,-1,-1,-1,0,1,1,1,2});
	Solution sl;
	int result = sl.threeSumClosest(nums, 7);	
	cout << result << endl;
	return 0;
}