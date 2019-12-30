//
//  565. Array Nesting.h
//  leetcode
//
//  Created by andysheng on 2019/12/31.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _65__Array_Nesting_h
#define _65__Array_Nesting_h

#include "DataStructures.h"

namespace P565 {
    class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            int ret = 0;
            vector<int> count(nums.size(), 0);
            for (int i = 0; i < nums.size(); ++i) {
                int cursor = i;
                int step = 0;
                while (count[cursor] == 0) {
                    count[cursor] = step + 1;
                    step = count[cursor];
                    cursor = nums[cursor];
                }
                ret = max(ret, step);
            }
            return ret;
        }
    };
}
#endif /* _65__Array_Nesting_h */
