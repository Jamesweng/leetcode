class Solution {
private:
    vector<vector<int>> f;
    vector<vector<int>> nums;
    int n, m;
    int calc(int x, int y) {
        if (f[x][y] != -1) return f[x][y];
        
        if (x == n - 1 && y == m - 1) {
            if (nums[x][y] <= 0) f[x][y] = -nums[x][y] + 1;
            else f[x][y] = 1;
        } else {
            if (x < n - 1) {
                int tmp = calc(x + 1, y);
                f[x][y] = tmp - nums[x][y];
                if (f[x][y] <= 0) f[x][y] = 1;
            }

            if (y < m - 1) {
                int tmp = calc(x, y + 1);
                int b = -nums[x][y] + tmp;
                if (f[x][y] == -1 || f[x][y] > b) f[x][y] = b;
                if (f[x][y] <= 0) f[x][y] = 1;
            }
        }
        
        return f[x][y];
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) return 0;
        
        n = dungeon.size();
        m = dungeon[0].size();
      //  printf("n=%d\nm=%d\n", n, m);
        nums = dungeon;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i].resize(m);
            for (int j = 0; j < m; ++j) {
                f[i][j] = -1;
            }
        }
        
        int ans = calc(0, 0);
        return ans;
    }
};
