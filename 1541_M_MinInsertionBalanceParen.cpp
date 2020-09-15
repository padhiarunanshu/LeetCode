  
/**
 * https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * @brief  : LC 1541. Minimum Insertions to Balance a Parentheses String
 * @author : apadhi
 */
 
 // using stack...
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int res = 0;
        size_t n = s.size();
        
        for(size_t i = 0; i < n; ) {
            if(s[i] == '(') {
                st.push(s[i]);
                i++;
            } else {
                if(st.empty()) {
                    if(i+1 < n && s[i+1] == ')') {
                        res++; i += 2;
                    } else {
                        res += 2; i++;
                    }
                } else {
                    if(i+1 < n && s[i+1] == ')') { // means already brackets are balanced
                        i += 2;
                    } else {
                        res++ ; i++;
                    }
                    st.pop();
                }
            }            
        }        
        while(!st.empty()) {
            st.pop();
            res += 2;
        }
        return res;
    }
};

// without stack
// class Solution {
// public:
//     int minInsertions(string s) {
//         int ans =0 ,k=0, n =s.size();
//         for(int i = 0 ; i < n; i++)
//         {
//             char ch = s[i] ;
//             if(ch == '(')
//                 k++;
//             else
//             {
//                 if(k==0) // '(' is not present so add it
//                 {
//                     ans++; k++;
//                 }
//                 if( i+1 < n && s[i+1] == ')' )
//                 {
//                     i = i+1;
//                 }
//                 else
//                 {
//                     ans++;
//                 }
//                 k--; //remove '('
//             }
//         }
//         return ans + k*2 ;
//     }
// };
