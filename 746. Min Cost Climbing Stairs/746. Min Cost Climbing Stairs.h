//
//  746. Min Cost Climbing Stairs.h
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _46__Min_Cost_Climbing_Stairs_h
#define _46__Min_Cost_Climbing_Stairs_h

#include <vector>

using namespace std;

namespace MinCostClimbingStairs {
    class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int dp[cost.size()];
            memset(dp, 0, sizeof(int) * cost.size());
            
            dp[0] = 0;
            dp[1] = 0;
            
            for (int i = 2; i < cost.size(); ++i) {
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            }
            
            return min(dp[cost.size() - 1] + cost[cost.size() - 1], dp[cost.size() - 2] + cost[cost.size() - 2]);
        }
    };
}
#endif /* _46__Min_Cost_Climbing_Stairs_h */
