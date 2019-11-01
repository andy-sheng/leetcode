//
//  1043. Partition Array for Maximum Sum.h
//  leetcode
//
//  Created by andysheng on 2019/11/2.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _043__Partition_Array_for_Maximum_Sum_h
#define _043__Partition_Array_for_Maximum_Sum_h
#include <vector>
#include <algorithm>
using namespace std;
namespace PartitionArrayForMaximumSum {
    class Solution {
    public:
        int maxSumAfterPartitioning(vector<int>& A, int K) {
            vector<int> dp(A.size(), -1);
            for (int i = 0; i < A.size(); ++i) {
                int maxNum = -1;
                for (int j = 0; j < K && (i - j) > -1; ++j) {
                    maxNum = max(maxNum, A[i - j]);
                    int val = i - j - 1 < 0 ? maxNum * (j + 1) : maxNum * (j + 1) + dp[i - j -1];
                    if (val > dp[i]) {
                        dp[i] = val;
                    }
                }
                
            }
            return dp[A.size() - 1];
        }
    };
}
#endif /* _043__Partition_Array_for_Maximum_Sum_h */
