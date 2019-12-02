//
//  1017. Convert to Base -2 .h
//  leetcode
//
//  Created by andysheng on 2019/12/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _017__Convert_to_Base__2__h
#define _017__Convert_to_Base__2__h

#include "DataStructures.h"

namespace P1017 {
    class Solution {
    public:
        string baseNeg2(int N) {
            if (N == 0) return "0";
            string ret = "";
            while (N != 0) {
                int val = 0;
                if (N < 0) {
                    val = abs(N % -2);
                    N = (N - 1)/ -2;
                } else {
                    val = N % -2;
                    N /= -2;
                }
                ret = to_string(val) + ret;
            }
            return ret;
        }
    };
}

#endif /* _017__Convert_to_Base__2__h */
