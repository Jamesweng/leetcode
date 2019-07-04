class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = nums.size() - 1;
        
        while (b < c) {
            while (a < c && nums[a] == 0) a++;
            while (c > a && nums[c] == 2) c--;
            if (a < c && nums[a] == 2) {
                swap(nums[a], nums[c]);
                c--;
            }
            if (a < c && nums[c] == 0) {
                swap(nums[a], nums[c]);
                a++;
            }
            if (b < a) b = a;
            while (b < c && nums[b] == 1) b++;
            if (b < c && a < b && nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;
            }
            if (b < c && nums[b] == 2) {
                swap(nums[b], nums[c]);
                c--;
            } 
        }
    }
};
