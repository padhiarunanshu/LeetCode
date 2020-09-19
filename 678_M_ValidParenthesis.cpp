/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @brief  : LC 678. Valid Parenthesis String
 * @author : apadhi
 --------------------------------------------------------------------------------------------
 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parenthesis String.
 Memory Usage: 6.3 MB, less than 24.51% of C++ online submissions for Valid Parenthesis String.
 --------------------------------------------------------------------------------------------
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> paren;
        stack<int> star;
        
        int i = 0;
        
        for(char c : s) {
            if(c == '(') {
                paren.push(i);
            } else if (c == '*') {
                star.push(i);
            } else {
                if(!paren.empty()) {
                    paren.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
            i++;
        }
        
        while(!paren.empty()) {
            if(star.empty()) return false;
            else if(star.top() > paren.top()) {
                star.pop(); paren.pop();
            } else {
                return false;
            }
        }
        
        return true;
    }
};
