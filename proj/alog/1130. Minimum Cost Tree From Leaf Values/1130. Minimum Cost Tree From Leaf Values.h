//
//  1130. Minimum Cost Tree From Leaf Values.h
//  leetcode
//
//  Created by andysheng on 2019/11/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _130__Minimum_Cost_Tree_From_Leaf_Values_h
#define _130__Minimum_Cost_Tree_From_Leaf_Values_h

#include "DataStructures.h"



namespace MinimumCostTreeFromLeafValues {
    class Solution {
    public:
        int mctFromLeafValues(vector<int>& arr) {
            
            
            vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
            
            dpSolution(arr, dp, 0, arr.size() - 1);
            return dp[0][arr.size() - 1];
        }
        
        void dpSolution(vector<int>& arr, vector<vector<int>> &dp, int begin, int end) {
            if (begin == end) {
                dp[begin][end] = 0;
                return;
            }
            if (dp[begin][end] > 0) {
                return;
            }
            
            int ret = INT_MAX;
            for (int i = begin; i < end; ++i) {
                dpSolution(arr, dp, begin, i);
                dpSolution(arr, dp, i + 1, end);
                int leftTreeCost = dp[begin][i];
                int rightTreeCost = dp[i + 1][end];
                int maxLeft = 0, maxRight = 0;
                for (int j = begin; j <= i; ++j) maxLeft = max(maxLeft, arr[j]);
                for (int j = i + 1; j <= end; ++j) maxRight = max(maxRight, arr[j]);
                ret = min(ret, leftTreeCost + rightTreeCost + maxLeft * maxRight);
            }
            dp[begin][end] = ret;
        }
    };
}

#endif /* _130__Minimum_Cost_Tree_From_Leaf_Values_h */
