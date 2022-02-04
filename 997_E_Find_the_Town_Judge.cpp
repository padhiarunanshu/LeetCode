class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> followers(n+1, 0);
        vector<int> does_follow(n+1, 0);
        
        for (auto vec : trust) {
            followers[vec[1]]++;
            does_follow[vec[0]] = 1;
        }
        
        vector<int> townjudge = {};
        for(int i = 1; i <= n; ++i) {
            if(followers[i] == n-1 && does_follow[i] == 0) {
                townjudge.push_back(i);
            }
        }
        
        if(townjudge.size() != 1) return -1;
        return townjudge[0];
    }
};



/*
Runtime: 235 ms, faster than 62.49% of C++ online submissions for Find the Town Judge.
Memory Usage: 68.9 MB, less than 27.55% of C++ online submissions for Find the Town Judge.
*/
