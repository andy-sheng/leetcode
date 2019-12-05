//
//  712. Minimum ASCII Delete Sum for Two Strings.h
//  leetcode
//
//  Created by andysheng on 2019/12/6.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _12__Minimum_ASCII_Delete_Sum_for_Two_Strings_h
#define _12__Minimum_ASCII_Delete_Sum_for_Two_Strings_h

#include "DataStructures.h"
namespace P712 {
    class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            int total = 0;
            vector<vector<int>> dp(s2.size(), vector<int>(s1.size(), 0));
            
            dp[0][0] = (s1[0] == s2[0]) ? s1[0] : 0;
            total += s1[0] + s2[0];
            for (int i = 1; i < s1.size(); ++i) {
                total += s1[i];
                dp[0][i] = max((s1[i] == s2[0]) ? s1[i] : 0, dp[0][i-1]);
            }
            for (int i = 1; i < s2.size(); ++i) {
                total += s2[i];
                dp[i][0] = max((s1[0] == s2[i]) ? s1[0] : 0, dp[i - 1][0]);
            }

            for (int i = 1; i < s2.size(); ++i) {
                for (int j = 1; j < s1.size(); ++j) {
                    dp[i][j] = dp[i - 1][j - 1] + ((s1[j] == s2[i]) ? s1[j] : 0);
                    dp[i][j] = max(dp[i-1][j], dp[i][j]);
                    dp[i][j] = max(dp[i][j-1], dp[i][j]);
                }
            }
            
            return total - 2 * dp[s2.size() - 1][s1.size() - 1];
        }
    };
}
#endif /* _12__Minimum_ASCII_Delete_Sum_for_Two_Strings_h */
