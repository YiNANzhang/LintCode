class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        //vector<int> ret = nums;
        if (nums.size() < 2) return nums; 
        auto pivot = nums.rbegin();
        pivot = next(pivot);
        while (pivot != nums.rend() && *(pivot) >= *prev(pivot)) pivot = next(pivot);
        if (pivot != nums.rend()) {
            auto change = find_if(nums.rbegin(), nums.rend(), bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        }
        reverse(nums.rbegin(), pivot);
        return nums;
    }
};

