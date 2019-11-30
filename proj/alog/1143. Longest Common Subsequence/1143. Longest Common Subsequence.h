//
//  1143. Longest Common Subsequence.h
//  leetcode
//
//  Created by andysheng on 2019/12/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _143__Longest_Common_Subsequence_h
#define _143__Longest_Common_Subsequence_h

#include "DataStructures.h"

namespace P1143 {
    class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text2.size(), vector<int>(text1.size(), 0));
            
            dp[0][0] = text1[0] == text2[0];
            for (int i = 1; i < text1.size(); ++i) {
                dp[0][i] = max((int)(text1[i] == text2[0]), dp[0][i-1]);
            }
            for (int i = 1; i < text2.size(); ++i) {
                dp[i][0] = max((int)(text1[0] == text2[i]), dp[i - 1][0]);
            }

            for (int i = 1; i < text2.size(); ++i) {
                for (int j = 1; j < text1.size(); ++j) {
                    dp[i][j] = dp[i - 1][j - 1] + (text1[j] == text2[i]);
                    dp[i][j] = max(dp[i-1][j], dp[i][j]);
                    dp[i][j] = max(dp[i][j-1], dp[i][j]);
                }
            }
            return dp[text2.size() - 1][text1.size() - 1];
        }
    };
}
#endif /* _143__Longest_Common_Subsequence_h */
