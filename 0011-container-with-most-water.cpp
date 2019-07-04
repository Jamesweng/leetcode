#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector< pair<int, int> > numbs;
        vector<int> mins, maxs;
        
        for (int i = 0; i < height.size(); ++i) {
            numbs.push_back(make_pair(height[i], i));
            mins.push_back(0);
            maxs.push_back(0);
        }
        
        sort(numbs.begin(), numbs.end());
        
        for (int i = numbs.size() - 1; i >= 0; --i) {
            if (i == numbs.size() - 1) {
                mins[i] = maxs[i] = numbs[i].second;
            }
            else {
                mins[i] = min(mins[i + 1], numbs[i].second);
                maxs[i] = max(maxs[i + 1], numbs[i].second);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            int h = height[i];
            pair<int, int> p(h, -1);
            int pos = lower_bound(numbs.begin(), numbs.end(), p) - numbs.begin();
            if (pos == numbs.size()) continue;
            if (mins[pos] < i) {
                int cur = h * (i - mins[pos]);
                ans = max(ans, cur);
            }
            if (maxs[pos] > i) {
                int cur = h * (maxs[pos] - i);
                ans = max(ans, cur);
            }
        }
        
        return ans;
    }
};
