/**
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * @brief  : LC 151. Reverse Words in a String
 * @author : apadhi
 */

class Solution {
public:
    
    string reverse(string s) {
        int len = s.length();
        
        for(int i = 0, j = len - 1; i < j; i++, j-- ) {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
        return s;
    }
    
    // abc bcd -> dcb cba -> bcd abc
    string reverseWords(string s) {
        string rev = reverse(s);
        
        std::istringstream iss(rev);
        vector<string> vec((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
        
        string result = "", space = " ";
        for(int i = 0; i < vec.size(); i++) {
            result += reverse(vec[i]);
            result += space;
        }
        
        return result.substr(0, result.size() - 1);
        
    }
};
