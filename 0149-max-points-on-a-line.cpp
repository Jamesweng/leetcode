class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (long long)a.second * b.first < (long long)b.second * a.first;
    }
    static bool equal(pair<int, int>&a, pair<int, int>&b) {
        return (long long)a.second * b.first == (long long)b.second * a.first;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        if (n <= 2) return n;
        
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            vector<pair<int,int>> ks;
            int identical = 1;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int nx = points[j][0], ny = points[j][1];
                    
                    if (nx == x && ny == y) {
                        identical++;
                        continue;
                    }
                    ks.push_back(make_pair(nx - x, ny - y));
                }
            }
            if (ks.empty()) {
                ans = max(ans, identical);
                continue;
            }
            sort(ks.begin(), ks.end(), cmp);
            
            pair<int, int> k = ks[0];
            int cnt = 1;
            for (int j = 1; j < ks.size(); ++j) {
                if (!equal(ks[j], k)) {
                    ans = max(ans, cnt + identical);
                    k = ks[j];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            ans = max(ans, cnt + identical);
        }
        return ans;
    }
};
