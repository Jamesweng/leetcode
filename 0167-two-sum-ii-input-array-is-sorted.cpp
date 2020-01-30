class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        
        for (int i = 0, j = numbers.size() - 1; i < j; ) {
            int sum = numbers[i] + numbers[j];
            
            if (sum > target) {
                j--;
            } else if (sum < target) {
                ++i;
            } else {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        
        return ans;
    }
};
