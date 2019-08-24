class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        
        vector<int> candies(ratings.size(), 1);
        bool done = false;
        int dir = 1;
        while (!done) {
            done = true;
            for (int i = dir > 0 ? 0 : ratings.size() - 1; 
                 i >= 0 && i < ratings.size(); i += dir) {
                if (i > 0 && ratings[i] > ratings[i - 1] && 
                    candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    done = false;
                }
            
                if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1] && 
                   candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    done = false;
                }
            }
            dir = -dir;
        }
        
        int sum = 0;
        for (int i = 0; i < ratings.size(); ++i) sum += candies[i];
        return sum;
    }
};
