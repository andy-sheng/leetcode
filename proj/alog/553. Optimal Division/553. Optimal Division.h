//
//  553. Optimal Division.h
//  leetcode
//
//  Created by andysheng on 2019/12/20.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _53__Optimal_Division_h
#define _53__Optimal_Division_h

#include "DataStructures.h"

namespace P553 {
    class Solution {
    public:
        string optimalDivision(vector<int>& nums) {
            if (nums.size() == 1) {
                return to_string(nums[0]);
            } else if (nums.size() == 2) {
                return to_string(nums[0]) + "/" + to_string(nums[1]);
            }
            string ret = to_string(nums[0]) + "/(" + to_string(nums[1]);
            for (int i = 2; i < nums.size(); ++i) {
                ret = ret + "/" + to_string(nums[i]);
            }
            ret += ")";
            return ret;
        }
    };
}
#endif /* _53__Optimal_Division_h */
