//
//  983. Minimum Cost For Tickets.h
//  leetcode
//
//  Created by andysheng on 2019/11/24.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _83__Minimum_Cost_For_Tickets_h
#define _83__Minimum_Cost_For_Tickets_h
#include "DataStructures.h"
namespace MinimumCostForTickets {
    class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            vector<int> dp(days.size(), 0);
            for (int i = 0; i < days.size(); ++i) {
                int oneDay = costs[0] + ((i - 1 > -1) ? dp[i - 1] : 0);
                int oneWeek = costs[1];
                // could be optimised using binary search
                for (int j = i - 1; j > -1; --j) {
                    if (days[i] - days[j] > 6) {
                        oneWeek += dp[j];
                        break;
                    }
                }
                int oneMonth = costs[2];
                for (int j = i - 1; j > -1; --j) {
                    if (days[i] - days[j] > 29) {
                        oneMonth += dp[j];
                        break;
                    }
                }
                dp[i] = min(oneDay, min(oneWeek, oneMonth));
            }
            for (int cost: dp) {
                cout << cost << endl;
            }
            return dp.back();
        }
    };
}
#endif /* _83__Minimum_Cost_For_Tickets_h */
