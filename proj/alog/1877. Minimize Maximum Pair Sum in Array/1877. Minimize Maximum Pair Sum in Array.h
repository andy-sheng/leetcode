//
//  1877. Minimize Maximum Pair Sum in Array.h
//  leetcode
//
//  Created by andysheng on 2021/7/23.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _877__Minimize_Maximum_Pair_Sum_in_Array_h
#define _877__Minimize_Maximum_Pair_Sum_in_Array_h

#include "DataStructures.h"

namespace P1877 {

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0, j = nums.size(); i < j; ++i, --j) {
            ret = max(ret, nums[i] + nums[j]);
        }
        return ret;
    }
};

}

#endif /* _877__Minimize_Maximum_Pair_Sum_in_Array_h */
