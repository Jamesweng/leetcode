class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty()) return 0;
        
        int n = gas.size(), i, j, sum;
        for (i = n, j = n, sum = gas[0] - cost[0]; j - i + 1 != n; ) {
            if (sum <= 0) i--, sum += (gas[i % n] - cost[i % n]);
            else j++, sum += (gas[j % n] - cost[j % n]);
        }
        
        if (sum < 0) return -1;
        else return i % n;
    }
};
