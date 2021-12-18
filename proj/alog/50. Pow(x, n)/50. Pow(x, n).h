//
//  50. Pow(x, n).h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _0__Pow_x__n__h
#define _0__Pow_x__n__h

#include "DataStructures.h"

namespace P50 {
class Solution {
private:
    unordered_map<int, double> cache;
public:
    double myPow(double x, int n) {
        cache[1] = x;
        cache[2] = x * x;
        if (n == 0) {
            return 1;
        } else if (n > 0) {
            return doPow(x, n);
        } else {
            return 1.0 / doPow(x, - ((long long)n));
        }
    }
    double doPow(double x, long long n) {
        if (cache.find(n) == cache.end()) {
            double tmp =  doPow(x, n / 2) ;
            return tmp * tmp * (n%2 ? x : 1);
        } else {
            return cache[n];
        }
    }
};

}
#endif /* _0__Pow_x__n__h */
