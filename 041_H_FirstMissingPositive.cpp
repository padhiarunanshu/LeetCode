/**
 * https://leetcode.com/problems/first-missing-positive/
 * @brief  : LC 41. First Missing Positive
 * @author : apadhi
 */
 
class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      int res = 0, sz = nums.size();
      for(size_t i = 0; i < sz; ++i) {
        while(nums.at(i) >= 1 and nums.at(i) <= sz && nums.at(i) != nums[nums.at(i)-1]) {
          swap(nums.at(i), nums[nums.at(i)-1]);
        }
      }
      for(size_t i = 0; i < sz; ++i) {
        if (nums.at(i) != i + 1) {
          return i + 1;
        }
      }
      return sz + 1;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
Memory Usage: 9.8 MB, less than 61.18% of C++ online submissions for First Missing Positive.
*/
