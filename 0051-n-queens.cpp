class Solution {
private:
    static const int MAXN = 20;
    bool cols[MAXN], cros1[MAXN + MAXN], cros2[MAXN + MAXN];
    vector<vector<string>> ans;
    
    void search(int y, int n, vector<string>& cur) {
        if (y == n) {
            ans.push_back(cur);
            return;
        }
        
        for (int x = 0; x < n; ++x) {
            if (cols[x]) continue;
            
            int w = x + y, z = n - 1 - x + y;
            if (cros1[w] || cros2[z]) continue;
            
            cols[x] = cros1[w] = cros2[z] = true;
            cur[y][x] = 'Q';
            
            search(y + 1, n, cur);
            
            cols[x] = cros1[w] = cros2[z] = false;
            cur[y][x] = '.';
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> cur;
        string empty_str;
        for(int i = 0; i < n; ++i) empty_str += '.';
        for(int i = 0; i < n; ++i) cur.push_back(empty_str);
        search(0, n, cur);
        return ans;
    }
};
