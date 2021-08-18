//
//  91. Decode Ways .h
//  leetcode
//
//  Created by andysheng on 2021/8/19.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _1__Decode_Ways__h
#define _1__Decode_Ways__h

#include "DataStructures.h"
namespace P91 {

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        int n_2 = 1;
        int n_1 = s.back() != '0';
        for (int i = (int)s.size() - 2; i > -1; --i) {
            int tmp = 0;
            if (s[i] != '0') {
                tmp = n_1;
                int val = (s[i] - '0') * 10 + s[i + 1] - '0';
                if (val <= 26) {
                    tmp += n_2;
                }
            }
            n_2 = n_1;
            n_1 = tmp;
        }
        return n_1;
    }
};

}

#endif /* _1__Decode_Ways__h */
