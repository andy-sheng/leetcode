//
//  90. Subsets II.h
//  leetcode
//
//  Created by andysheng on 2021/8/20.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _0__Subsets_II_h
#define _0__Subsets_II_h

#include "DataStructures.h"

namespace P90 {

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) { return {{}}; }
        vector<vector<int>> ret = {};
        sort(nums.begin(), nums.end());
        ret.push_back({nums.front()});
        int subSetCount = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int idx = (int)ret.size() - 1;
            int subsetToAdd = subSetCount;
            if (num != nums[i-1]) {
                subSetCount = (int)ret.size() + 1;
                subsetToAdd = subSetCount - 1;
                ret.push_back({num});
            }
            for (; subsetToAdd > 0; --subsetToAdd, --idx) {
                vector<int> subSet = ret[idx];
                subSet.push_back(num);
                ret.push_back(subSet);
            }
        }
        ret.push_back({});
        return ret;
    }
};

}
#endif /* _0__Subsets_II_h */
