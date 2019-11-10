//
//  931. Minimum Falling Path Sum.h
//  leetcode
//
//  Created by andysheng on 2019/11/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _31__Minimum_Falling_Path_Sum_h
#define _31__Minimum_Falling_Path_Sum_h


namespace MinimumFallingPathSum {
    class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& A) {
            vector<vector<int>> dp(A.size(), vector<int>(A[0].size()));
            for (int row = 0 ; row < A.size(); ++row) {
                for (int col = 0; col < A[0].size(); ++col) {
                    if (row == 0) {
                        dp[0][col] = A[0][col];
                    } else {
                        int fromCol = col;
                        if (col > 0 && dp[row - 1][col - 1] < dp[row - 1][fromCol]) {
                            fromCol = col - 1;
                        }
                        if (col < A[0].size() - 1 && dp[row - 1][col + 1] < dp[row - 1][fromCol]) {
                            fromCol = col + 1;
                        }
                        dp[row][col] = dp[row - 1][fromCol] + A[row][col];
                    }
                }
            }
            int ret = -1;
            for (int val : dp[A.size() - 1]) {
                ret = max(ret, val);
            }
            return ret;
        }
    };
}
#endif /* _31__Minimum_Falling_Path_Sum_h */
