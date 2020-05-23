/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 * @brief  : LC 33. Search in Rotated Sorted Array
 * @author : apadhi
 */

class Solution {
public:
    int findPivot(vector<int>& nums, int low, int high) {        
        int mid = -1;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                break;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid+1]) {
                high = mid - 1;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid+1]) {
                low = mid + 1;
            }
        } 
        return mid;
    }
    
    int binSearch(vector<int>& nums, int target, int low, int high) {
        if (high >= low) {
            int mid = low + (high - low)/2;
            cout << " target = " << target << " | mid = " << mid << endl;
            if(target == nums[mid]) return mid;
            else if (target > nums[mid]) return binSearch(nums, target, mid + 1, high);
            else return binSearch(nums, target, low, mid - 1);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        int pivot = findPivot(nums, low, high); //pivot--;
        // cout << pivot << endl;
        
        // low - pivot - 1, pivot - high -- bin search
        int res = -1;
        
        res = binSearch(nums, target, low, pivot - 1);
        if(nums[res] == target) return res;
        
        res = binSearch(nums, target, pivot, high);
        if(nums[res] ==  target) return res;
        
        return -1;
    }
    
    // This algorithm works in signle pass. O(log n) time
    int search(vector<int>& nums, int target) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (low <= high) {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] >= nums[low]) {
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
