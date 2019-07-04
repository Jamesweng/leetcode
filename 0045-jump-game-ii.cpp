class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int f[nums.size()];
        int rmq[nums.size()][32];
        // rmq[i][j] = min(f[i...i+2^j - 1])
        // rmq[i][0] = f[i]
        // rmq[i][j] = min(rmq[i][j - 1], rmq[i + 2^(j-1)][j - 1])
        // f[i] = min(f[i + j]) + 1, j = 1..nums[i]
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i == nums.size() - 1) {
                f[i] = 0;
            } else {
                f[i] = 0x7ffffffe;
                int a = min(nums[i], (int)(nums.size() - i - 1));
                ++a;
                if (a > 0) {
                   f[i] = f[i + 1] + 1;
                   a--;
                }
                if (a > 0) {
                    int k = i+1;
                
                    int x = log(a)/log(2.0) + 1;
                    for (int j = x; j >= 0; --j) {
                        if ((a & (1 << j)) != 0) {
                            f[i] = min(f[i], rmq[k][j] + 1);
                            k += ((1 << j));
                        }    
                    }
                }
            }
            rmq[i][0] = f[i];
            for (int j = 1; j <= 31 && i + (1 << (j - 1)) < nums.size(); ++j) {
                rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        return f[0];
    }
};
