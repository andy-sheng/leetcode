//
//  1630. Arithmetic Subarrays.h
//  leetcode
//
//  Created by andysheng on 2021/7/25.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _630__Arithmetic_Subarrays_h
#define _630__Arithmetic_Subarrays_h

#include "DataStructures.h"

namespace P1630 {

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret(l.size(), true);
        for (int i = 0; i < l.size(); ++i) {
            if (r[i] - l[i] == 1) {
                continue;
            }
            vector<int> cpy(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(cpy.begin(), cpy.end());
            int diff = cpy[1] - cpy[0];
            for (int j = 2; j < cpy.size(); ++j) {
                if (cpy[j] - cpy[j-1] != diff) {
                    ret[i] = false;
                    break;
                }
            }
        }
        return ret;
    }
};

}
#endif /* _630__Arithmetic_Subarrays_h */
