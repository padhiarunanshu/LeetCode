/**
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * @brief  : LC 1249. Minimum Remove to Make Valid Parentheses
 * @author : apadhi
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size = s.size();
        int count = 0;
        string res = "";
        for(char c : s) {
            if(c == '(') {
                count++;
            } else if(c == ')') {
                if(count == 0)
                    continue;
                count--;
            }
            res.append(1,c);
        }
        
        cout << count << "  " << res << endl;
        
        for(int i = res.length() - 1; i >= 0; i--) {
            if(res[i] == '(' && count-- > 0) 
                res.erase(i,1);
        }

        return res;        
    }
};

/*
Runtime: 68 ms, faster than 85.57% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
Memory Usage: 11.2 MB, less than 63.40% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
 */
