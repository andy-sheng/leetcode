//
//  1004. Max Consecutive Ones III.h
//  leetcode
//
//  Created by andysheng on 2019/11/22.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _004__Max_Consecutive_Ones_III_h
#define _004__Max_Consecutive_Ones_III_h
#include "DataStructures.h"
namespace MaxConsecutiveOnesIII {
    class Solution {
    public:
        int longestOnes(vector<int>& A, int K) {
            int start = 0;
            int ret = 0, oneCnt = 0, zeroCnt = 0;
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] == 1) {
                    ++oneCnt;
                } else {
                    ++zeroCnt;
                    if (zeroCnt > K) {
                        ret = max(ret, oneCnt + K);

                        for (; start < A.size() && A[start] != 0; ++start) {
                            --oneCnt;
                        }
                        for (; zeroCnt > 0 && start < A.size() && A[start] != 1; ++start) {
                            --zeroCnt;
                        }

                    }
                }
            }
            if (oneCnt > 0 && zeroCnt <= K) {
                ret = min(max(ret, oneCnt + K), (int)A.size());
            }
            return ret;
        }
        
        int longestOnes2(vector<int>& A, int K) {
            int lastDP = 0;
            int ret = 0;
            for (int from = A.size() - 1; from > -1; --from) {
                for (int to = from; to < A.size(); ++to) {
                    if (to == from) {
                        lastDP = !A[from];
                    } else {
                        lastDP = lastDP + !A[to];
                    }
                    if (lastDP <= K) {
                        ret = max(ret, to - from + 1);
                        ret = min(ret, (int)A.size());
                    }
                }
            }
            return ret;
        }
    };
}
#endif /* _004__Max_Consecutive_Ones_III_h */
