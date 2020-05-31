/**
 * https://leetcode.com/problems/interval-list-intersections/
 * @brief  : LC 986. Interval List Intersections
 * @author : apadhi
 */

/**
Runtime: 68 ms, faster than 65.59% of C++ online submissions for Interval List Intersections.
Memory Usage: 18.6 MB, less than 8.00% of C++ online submissions for Interval List Intersections.
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> resVec;
        vector<int> found(2);
        unsigned int aPtr = 0, bPtr = 0;
        
        while(aPtr < A.size() && bPtr < B.size()) {
            if(B[bPtr][1] >= A[aPtr][0] && B[bPtr][0] <= A[aPtr][1]) {
                found[0] = max(A[aPtr][0], B[bPtr][0]);
                found[1] = min(A[aPtr][1], B[bPtr][1]);
                resVec.push_back(found);
            }
            
            (A[aPtr][1] <= B[bPtr][1]) ? aPtr++ : bPtr++;
        }
        return resVec;
    }
};

