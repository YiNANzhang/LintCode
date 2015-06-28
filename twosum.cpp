#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
		unordered_map<int, int> hsh;
		for (int i = 0; i < nums.size(); ++i) {
			if (hsh.find(target - nums[i]) != hsh.end()) {
				return vector<int> ({hsh[target-nums[i]], i+1}); 
			} else {
				hsh.insert(make_pair(nums[i], i+1));
			}
		}
		return vector<int>();
    }
};



int main() {
	vector<int> nums({1,0,-1});
	int target = -1;
	Solution sl;
	vector<int> result = sl.twoSum(nums, target);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}