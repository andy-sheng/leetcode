//
//  639. Decode Ways II.h
//  leetcode
//
//  Created by andysheng on 2021/8/19.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _39__Decode_Ways_II_h
#define _39__Decode_Ways_II_h

#include "DataStructures.h"

namespace P639 {

class Solution {
public:
    int numDecodings(string s) {
        long n_2 = 1;
        long n_1 = s.back() == '*' ? 9 : s.back() != '0';
        for (int i = (int)s.size() - 2; i > -1; --i) {
            long tmp = 0;
            if (s[i] == '*') {
                tmp = 9 * n_1;
                if (s[i+1] == '*') {
                    tmp += 15 * n_2;
                } else {
                    tmp += ((s[i+1] <= '6') ? 2  : 1) * n_2;
                }
            }
            else if (s[i] != '0') {
                tmp = n_1;
                if (s[i + 1] == '*') {
                    if (s[i] == '1') {
                        tmp += 9 * n_2;
                    } else if (s[i] == '2') {
                        tmp += 6 * n_2;
                    }
                } else {
                    int val = (s[i] - '0') * 10 + s[i + 1] - '0';
                    if (val <= 26) {
                        tmp += n_2;
                    }
                }
                
            }
            n_2 = n_1;
            n_1 = tmp % 1000000007;
        }
        return n_1;
    }
};

}

#endif /* _39__Decode_Ways_II_h */
