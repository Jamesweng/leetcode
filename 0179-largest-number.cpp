class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for (int x : nums) {
            nums_str.emplace_back(to_string(x));
        }
        sort(nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
            string ab = a + b, ba = b + a;
            return ab > ba;
        });
        bool flag = false;
        string ans;
        for (auto& x : nums_str) {
            if (!flag && x == "0") {
                continue;
            } else {
                ans += x;
                flag = true;
            }
        }
        if (ans.empty()) ans = "0";
        return ans;
    }
};
