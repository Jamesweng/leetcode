class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int minNum(nums[0]), maxNum(nums[0]);
        for (auto num : nums) {
            minNum = min(minNum, num), maxNum = max(maxNum, num); 
        }
        
        int n = nums.size();
        
        int avgGap = (maxNum - minNum + n - 2) / (n - 1);
        int ans = avgGap;
        if (avgGap < 1) avgGap = 1;
        
        vector<pair<int, int>> slots(n, make_pair(-1, -1));
        
        std::for_each(nums.begin(), nums.end(),
                     [&slots, minNum, avgGap](auto num){
                         int slotId = (num - minNum) / avgGap;
                         if (slots[slotId].first == -1) {
                             slots[slotId].first = slots[slotId].second = num;
                         } else {
                            slots[slotId].first = min(slots[slotId].first, num);
                            slots[slotId].second = max(slots[slotId].second, num);
                         }
                     });
        
        int prevMax = -1;
        std::for_each(slots.begin(), slots.end(),
                     [&ans, &prevMax](auto slot) {
                         if (slot.first == -1) return;
                         
                         if (prevMax == -1) {
                             prevMax = slot.second;
                         } else {
                             ans = max(ans, slot.first - prevMax);
                             prevMax = slot.second;
                         }
                     });
            
        return ans;
    }
};
