//
//  29. Divide Two Integers.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _9__Divide_Two_Integers_h
#define _9__Divide_Two_Integers_h

#include "DataStructures.h"

namespace P29 {
    class Solution {
    private:
    public:
        int divide(int dividend, int divisor) {
            if (dividend == 0) return 0;
            bool neg = false;
            if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
                neg = true;
            }
            long long llDividend = llabs(dividend);
            long long llDivisor = llabs(divisor);
            vector<long long> cache {llDivisor};
            long long ret = 0;
            while (llDividend > 0 && !cache.empty()) {
                long long tmp = llDividend - cache.back();
                if (tmp >= 0) {
                    llDividend = tmp;
                    ret += 1 << (cache.size() - 1);
                    cache.push_back(cache.back() + cache.back());
                } else {
                    cache.pop_back();
                }
            }
            ret = neg ? -ret : ret;
            return ret > INT_MAX ? INT_MAX : ret;
        }
    };
}
#endif /* _9__Divide_Two_Integers_h */
