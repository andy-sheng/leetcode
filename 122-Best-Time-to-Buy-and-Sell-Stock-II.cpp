class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current, n = prices.size(), flag = 0, buyPrice = 0, profit = 0;
        for(current = 0; current < n; current++) {
            if (flag == 0) {//buy
                if ((current + 1 < n) && prices[current] < prices[current + 1]) {//going to rise
                    flag = 1;
                    buyPrice = prices[current];
                }
            } else {//sale
                if ((current + 1) == n || prices[current] > prices[current + 1]) {//going to fall
                    flag = 0;
                    profit = profit + prices[current] - buyPrice;
                }
            }
        }
        return profit;
    }
    
};