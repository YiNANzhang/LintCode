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
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        unordered_map<char, int> hsh;
        int begin = 0;
        int gap = 0;
        int end;
        for (end = 0; end < s.size(); ++end) {
            if (hsh.find(s[end]) != hsh.end() && hsh[s[end]] >= begin) {
               begin = hsh[s[end]] + 1; 
            }
            hsh[s[end]] = end;
            gap = max(gap, end - begin + 1);
        }
        //gap = max(gap, end - begin);
        return gap;
    }
};
int main() {
	Solution sl;
	cout << sl.lengthOfLongestSubstring("a++--javy");
	cout << endl;
	return 0;
}