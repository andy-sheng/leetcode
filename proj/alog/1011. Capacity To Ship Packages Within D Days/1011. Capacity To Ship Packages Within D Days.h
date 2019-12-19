//
//  1011. Capacity To Ship Packages Within D Days.h
//  leetcode
//
//  Created by andysheng on 2019/12/19.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _011__Capacity_To_Ship_Packages_Within_D_Days_h
#define _011__Capacity_To_Ship_Packages_Within_D_Days_h

#include "DataStructures.h"

namespace P1011 {
    class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int D) {
            int low = 0;
            int high = 0;
            for (auto weight: weights) {
                low = max(low, weight);
                high += weight;
            }
            low = max(low, low / D);
            
            int mid = high;
            while (low < high) {
                mid = (low + high) / 2;
                if (check(weights, D, mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return high;
        }
        
        bool check(vector<int>& weights, int D, int capcity) {
            int tmp = 0;
            for (auto weight: weights) {
                tmp += weight;
                if (tmp > capcity) {
                    --D;
                    tmp = weight;
                }
            }
            return D > 0;
        }
        
        int shipWithinDays2(vector<int>& weights, int D) {
            vector<vector<int>> dp(D, vector<int>(weights.size(), 50000 * 500));
            dp[0][0] = weights[0];
            for (int i = 1; i < weights.size(); ++i) {
                dp[0][i] = dp[0][i - 1] + weights[i];
            }
            for (int i = 1; i < D; ++i) {
                dp[i][0] = weights[0];
            }
            
            for (int d = 1; d < D; ++d) {
                for (int i = 1; i < weights.size(); ++i) {
                    int lastDayWeight = weights[i];
                    for (int j = i - 1; j > -1; --j) {
                        dp[d][i] = min(dp[d][i], max(lastDayWeight, dp[d - 1][j]));
                        if (lastDayWeight <= dp[d - 1][j]) {
                            lastDayWeight += weights[j];
                        } else {
                            break;
                        }
                    }
                }
            }
            return dp[D - 1][weights.size() - 1];
        }
    };
}
#endif /* _011__Capacity_To_Ship_Packages_Within_D_Days_h */
