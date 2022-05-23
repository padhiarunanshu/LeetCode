class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        size_t sz = numbers.size();
        for(int i = 0, j = sz-1; i < j; ) {
            if(numbers[i] + numbers[j] == target) {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            } else if(numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};