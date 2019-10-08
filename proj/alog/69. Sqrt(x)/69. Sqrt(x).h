//
//  69. Sqrt(x).h
//  leetcode
//
//  Created by andysheng on 2019/10/9.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _9__Sqrt_x__h
#define _9__Sqrt_x__h

namespace Sqrt {
    inline short compare(long guess, long target) {
        long lowBoundary = guess * guess;
        long highBoundary = (guess + 1) * (guess + 1);
        if (lowBoundary <= target && target < highBoundary) {
            // bingo
            return 0;
        } else if (highBoundary <= target) {
            // too small
            return -1;
        } else {
            // too big
            return 1;
        }
    }

    class Solution {
    public:
        int mySqrt(int x) {
            int low  = 0;
            int high = x;
            int mid;
            while (low <= high) {
                int mid = (low + high) / 2;
                short ret = compare(mid, x);

                if (ret == 0) {
                    return mid;
                } else if (ret == -1) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return mid;
        }
    };
}
#endif /* _9__Sqrt_x__h */
