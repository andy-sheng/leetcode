//
//  77. Combinations.h
//  leetcode
//
//  Created by andysheng on 2021/9/6.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _7__Combinations_h
#define _7__Combinations_h
#include "DataStructures.h"

namespace P77 {

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp(k, 0);
        for (int pos = 0; pos < k;) {
            ++tmp[pos];
            if (tmp[pos] > n - (k - pos) + 1) {
                if (pos == 0) {
                    return ret;
                } else {
                    --pos;
                }
            } else {
                if (pos == k - 1) {
                    ret.push_back(tmp);
                } else {
                    tmp[pos+1] = tmp[pos];
                    ++pos;
                }
            }
        }
        return ret;
    }
};

}
#endif /* _7__Combinations_h */
