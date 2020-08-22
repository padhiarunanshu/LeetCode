/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @brief  : LC 3. Longest Substring Without Repeating Characters
 * @author : apadhi
 */

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        int sz = s.size();
        int i = 0, j = 0;

        vector<int> count(255, 0);
        count[s[0]] = 1;
        int res = 1;

        while(j != sz - 1) {
            if(count[s[j+1]] == 0) {
                count[s[++j]]++;
                res = max(res, j - i + 1);
            } else {
                count[s[i]]--;
                i++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}