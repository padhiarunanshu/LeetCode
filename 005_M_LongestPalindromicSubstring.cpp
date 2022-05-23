class Solution {
public:
    string substrPalindrome(string s, int L, int R, string& palin, int& palinLen) {
        int len = s.length();
        while (L >= 0 && R < len && s[L] == s[R]) {
            if ((R - L + 1) > palinLen) {
                palin = s.substr(L, R-L+1);
                palinLen = (R - L + 1);
            }
            L -= 1; R += 1;
        }
        return palin;
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int L = 0, R = 0, palinLen = 0, len = s.length();
        string res = "", palin = "";
        
        for(int i = 0; i < len; i++) {
            L = R = i;
            substrPalindrome(s, L, R, palin, palinLen);
            if (res.size() < palin.size()) res = palin;
            
            L = i; R = i + 1;
            substrPalindrome(s, L, R, palin, palinLen);
            if (res.size() < palin.size()) res = palin;
        }
        return palin;
    }
};