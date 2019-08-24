class Solution {
private:
    const static int hash_count = 2;
    int primes[hash_count] = {12497,12503 /*25439,25447*/};
    vector<bool> hashes[hash_count];
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        for (int i = 0; i < hash_count; ++i) {
            hashes[i].resize(primes[i]);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < hash_count; ++j) {
                hashes[j][((nums[i] % primes[j]) + primes[j])%primes[j]] = true;
            }
        }
        
        int ans = 0x7fffffff;
        for (int i = 0; i < hash_count; ++i) {
            int x = 0, max_count = 0;
            for (int j = 0; j < primes[i] * 2; ++j) {
                if (hashes[i][j % primes[i]]) {
                    x++;
                } else {
                    if (x > max_count) max_count = x;
                    x = 0;
                }
            }
            if (x > max_count) max_count = x;
            if (max_count < ans) ans = max_count;
        }
        return ans;
    }
};
