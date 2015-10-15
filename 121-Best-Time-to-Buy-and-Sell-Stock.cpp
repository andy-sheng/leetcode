class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, tmp = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            tmp = tmp + prices[i] - prices[i - 1];
            if (tmp > 0) {
                if (tmp > max) {
                     max = tmp;
                }
            } else {
                tmp = 0;
            }
        }
        return max;
    }
    
};