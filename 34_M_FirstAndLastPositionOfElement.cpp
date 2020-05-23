/**
 * @brief : LC 34. Find First and Last Position of Element in Sorted Array
 * @author : apadhi
 */

class Solution {
public:
    int binSearch(vector<int>& nums, int target, int low, int high) {
        int firstPos = nums.size(); // outer bound
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low)/2;
            
            if(nums[mid] >= target) {
                firstPos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return firstPos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        int left = binSearch(nums, target, low, high);
        int right = binSearch(nums, target+1, left, high) - 1;
        
        if(left > right) {
            return {-1,-1};
        } else {
            return {left, right};
        }
    }
};
