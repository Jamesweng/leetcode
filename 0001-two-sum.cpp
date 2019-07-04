class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int> > num_pairs;
        for (int i = 0; i < nums.size(); ++i) {
            num_pairs.push_back(make_pair(nums[i], i));
        }
        sort(num_pairs.begin(), num_pairs.end());
        vector<int> ans;
        
        for (int i = 0, j = num_pairs.size() - 1; i < j; ) {
            int sum = num_pairs[i].first + num_pairs[j].first;
            if (sum > target) {
                --j;
            } else if (sum < target) {
                ++i;
            } else {
                ans.push_back(num_pairs[i].second);
                ans.push_back(num_pairs[j].second);
                break;
            }
        }
        
        return ans;
    }
};
