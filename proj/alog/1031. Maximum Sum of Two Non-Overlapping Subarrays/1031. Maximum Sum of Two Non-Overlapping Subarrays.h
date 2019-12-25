//
//  1031. Maximum Sum of Two Non-Overlapping Subarrays.h
//  leetcode
//
//  Created by andysheng on 2019/12/26.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _031__Maximum_Sum_of_Two_Non_Overlapping_Subarrays_h
#define _031__Maximum_Sum_of_Two_Non_Overlapping_Subarrays_h

namespace P1031 {

    class Solution {
    public:
        int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
            vector<int> sums(A.size(), A[0]);
            vector<int> forwardSumStack(A.size(), 0);
            vector<int> backwardSumStack(A.size(), 0);
            int maxSubarrayLen = max(L, M);
            for (int i = 1; i < A.size(); ++i) {
                sums[i] = sums[i - 1] + A[i];
                if (i >= maxSubarrayLen) {
                    sums[i] -= A[i - maxSubarrayLen];
                }
            }
            
            // debug
            for (auto i : sums) {
                cout << i << " ";
            }
            cout << endl;
            // end debug
            int minSubarrayLen = min(L, M);
            int sum = 0;
            for (int i = 0; i < A.size(); ++i) {
                sum += A[i];
                if (i >= minSubarrayLen) {
                    sum -= A[i - minSubarrayLen];
                    forwardSumStack[i] = max(sum, forwardSumStack[i - 1]);
                } else if (i == minSubarrayLen - 1) {
                    forwardSumStack[i] = sum;
                }
            }
            sum = 0;
            for (int i = A.size() - 1; i >= 0; --i) {
                sum = sum + A[i];
                if (i < A.size() - minSubarrayLen) {
                    sum -= A[i + minSubarrayLen];
                    backwardSumStack[i] = max(sum, backwardSumStack[i + 1]);
                } else if (i == A.size() - minSubarrayLen) {
                    backwardSumStack[i] = sum;
                }
            }
            // debug
            for (auto i : forwardSumStack) {
                cout << i << " ";
            }
            cout << endl;
            for (auto i : backwardSumStack) {
                cout << i << " ";
            }
            cout << endl;
            // end debug
            
            int ret = 0;
            for (int i = maxSubarrayLen - 1; i < A.size(); ++i) {
                int left = i - maxSubarrayLen - 1 >= 0 ? forwardSumStack[i - maxSubarrayLen - 1] : 0;
                int right = i + 1 < A.size() ? backwardSumStack[i + 1] : 0;
                ret = max(ret, sums[i] + max(left, right));
            }
            return ret;
        }
    };
}
#endif /* _031__Maximum_Sum_of_Two_Non_Overlapping_Subarrays_h */
