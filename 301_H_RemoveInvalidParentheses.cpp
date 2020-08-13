/**
 * https://leetcode.com/problems/remove-invalid-parentheses/submissions/
 * @brief  : LC 301. Remove Invalid Parentheses
 * @author : apadhi
 */
 class Solution {
  private:
    // util function
    bool isBalanced(const std::string& iParenStr) {
		int count = 0;
	
		for(char c : iParenStr) {
		if (c == '(') count++;
		else if (c == ')') count--;
	
		if (count < 0) return false;
		}
	
		return count == 0;
	}
	
	// class member
    std::map<std::string, bool> visitMap;

public:
    vector<string> removeInvalidParentheses(string s) {
      std::queue<std::string> bfsQ;
	  std::vector<std::string> sol;
      
	  bfsQ.push(s);
	  int found = 0;

      std::string parent = "", child = "";
      
	  while(!bfsQ.empty()) {
	    parent = bfsQ.front();
	    bfsQ.pop();
      
	    if (visitMap[parent]) continue;
	    
	    visitMap[parent] = 1;
      
	    if(isBalanced(parent)) {
	    	found = 1;
	    	sol.push_back(parent);
	    }
      
	    if(found) continue;
      
	    for(int i = 0; i < parent.size(); ++i) {
	      if(parent[i] == '(' || parent[i] == ')') {
	        child = parent.substr(0, i) + parent.substr(i+1, parent.size());
	        bfsQ.push(child);
	      }
	    }
	  }
	  return sol;
    }
};

/*
Runtime: 472 ms, faster than 16.21% of C++ online submissions for Remove Invalid Parentheses.
Memory Usage: 33.5 MB, less than 27.51% of C++ online submissions for Remove Invalid Parentheses.
*/
