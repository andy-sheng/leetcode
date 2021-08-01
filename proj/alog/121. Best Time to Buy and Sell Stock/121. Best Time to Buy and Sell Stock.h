//
//  121. Best Time to Buy and Sell Stock.h
//  leetcode
//
//  Created by andysheng on 2021/8/1.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _21__Best_Time_to_Buy_and_Sell_Stock_h
#define _21__Best_Time_to_Buy_and_Sell_Stock_h

namespace P121 {

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, tmp = 0;
        for (int i = 1; i < prices.size(); ++i) {
            tmp += prices[i] - prices[i-1];
            if (tmp > 0) {
                max = max(tmp, max);
            } else {
                tmp = 0;
            }
        }
        return max;
    }
};

}
#endif /* _21__Best_Time_to_Buy_and_Sell_Stock_h */
