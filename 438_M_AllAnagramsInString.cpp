/**
 *  https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * @brief  : LC 438. Find All Anagrams in a String
 * @author : apadhi
 */
 
// Similar to Permuation in a string problem. using sliding window technique

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len1 = p.length();
        int len2 = s.length();
        
        if (len2 < len1) return res;
        
        vector<int> p_vec(26,0);
        vector<int> s_vec(26,0);
        
        int it1 = 0, it2 = 0;
        
        for( ; it1 < len1; it1++) {
            p_vec[p[it1] - 'a'] += 1;
            s_vec[s[it1] - 'a'] += 1; // it1 = 0, 1, 2
        }
        it1--; // to point to the last char of len1
        
        while (it1 < len2) {
            if(p_vec == s_vec) {
               res.push_back(it2);
            }
            if(++it1 != len2) { // boundary check
                s_vec[s[it1] - 'a'] += 1;
            }
            s_vec[s[it2] - 'a'] -= 1;
            ++it2;
        }
        return res;
    }
};
