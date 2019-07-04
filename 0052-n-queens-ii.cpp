class Solution {
public:
    static const int MAXN = 20;
    bool cols[MAXN], cros1[MAXN + MAXN], cros2[MAXN + MAXN];
    
    int search(int y, int n) {
        if (y == n) {
            return 1;
        }
        
        int total = 0;
        for (int x = 0; x < n; ++x) {
            if (cols[x]) continue;
            
            int w = x + y, z = n - 1 - x + y;
            if (cros1[w] || cros2[z]) continue;
            
            cols[x] = cros1[w] = cros2[z] = true;
            
            total += search(y + 1, n);
            
            cols[x] = cros1[w] = cros2[z] = false;
        }
        return total;
    }
    
    int totalNQueens(int n) {
        return search(0, n);
    }
};

