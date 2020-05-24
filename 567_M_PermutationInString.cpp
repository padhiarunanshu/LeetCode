/**
 *  https://leetcode.com/problems/permutation-in-string/
 * @brief  : LC 567. Permutation in String
 * @author : apadhi
 */
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len2 < len1) return false;
        
        vector<int> s1_vec(26,0);
        vector<int> s2_vec(26,0);
        
        int it1 = 0, it2 = 0;
        
        for( ; it1 < len1; it1++) {
            s1_vec[s1[it1] - 'a'] += 1;
            s2_vec[s2[it1] - 'a'] += 1; // it1 = 0, 1, 2
        }
        it1--; // to point to the last char of len1

        // using sliding window technique
        while (it1 < len2) {
            if(s1_vec == s2_vec) return true;
            
            if(++it1 != len2) // boundary check
                s2_vec[s2[it1] - 'a'] += 1;
            
            s2_vec[s2[it2] - 'a'] -= 1;
            ++it2;
        }
        return false;
    }
};
