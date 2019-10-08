//
//  633. Sum of Square Numbers.h
//  leetcode
//
//  Created by andysheng on 2019/10/9.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _33__Sum_of_Square_Numbers_h
#define _33__Sum_of_Square_Numbers_h

#include <math.h>

namespace SumOfSquareNumbers {
    class Solution {
    public:
        bool judgeSquareSum(int c) {
            long lowBoundary = 0;
            long highBoundary = sqrt(c);
            while (lowBoundary <= highBoundary) {
                long sum = lowBoundary * lowBoundary + highBoundary * highBoundary;
                if (sum < c) {
                    ++lowBoundary;
                } else if (sum > c) {
                    --highBoundary;
                } else {
                    break;
                }
            }
            
            return lowBoundary <= highBoundary;
        }
    };
}
#endif /* _33__Sum_of_Square_Numbers_h */
