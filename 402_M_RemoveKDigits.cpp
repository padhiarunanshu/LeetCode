/**
 * https://leetcode.com/problems/remove-k-digits/
 * @brief  : LC 402. Remove K Digits
 * @date   : 15 Sep 2020
 * @author : apadhi
 */

#include <bits/stdc++.h>

class Solution {
public:
    string removeKdigits(string num, int k) { // n = 1432219, k = 3 -> 1219
        stack<char> dig;        
        int sz = num.size();
        
        for(char c : num) {
			while(!dig.empty() && k > 0 && dig.top() > c) {
				dig.pop();
				k--;
			}
            if(!dig.empty() || c != '0') {
                dig.push(c);
            }
        }
        while(!dig.empty() && k--) {
            dig.pop();
        }
        
        string ans = "";
        
        while(!dig.empty()) {
            ans = dig.top() + ans;
            dig.pop();
        }
        
        if(ans.empty()) ans = "0";
            
        return ans;
    }
};
