class Solution {
public:
    int countPalindrome(string s, int L, int R) {
        int result = 0, len = s.length();
        while (L >= 0 && R < len && s[L] == s[R]) {
            result++;
            L -= 1; R += 1;
        }
        return result;
    }
    
    int countSubstrings(string s) {
        int result = 0, L = 0, R = 0, len = s.length();
        
        for(int i = 0; i < len; i++) {
            L = R = i;
            result += countPalindrome(s, L, R);
            
            L = i; R = i + 1;
            result += countPalindrome(s, L, R);
        }
        
        return result;
    }
};