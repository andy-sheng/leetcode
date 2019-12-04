//
//  78. Subsets.h
//  leetcode
//
//  Created by andysheng on 2019/12/5.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _8__Subsets_h
#define _8__Subsets_h
#include "DataStructures.h"
namespace P78 {
    class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ret = subsets(nums, 0);
            ret.push_back(vector<int>());
            return ret;
        }
        vector<vector<int>> subsets(vector<int>& nums, int idx) {
            if (idx == nums.size() - 1) {
                return vector<vector<int>> {vector<int> {nums.back()}};
            }
            vector<vector<int>> ret = subsets(nums, idx + 1);
            for (int i = ret.size() - 1; i > -1; --i) {
                vector<int> tmp = vector<int> (ret[i].begin(), ret[i].end());
                tmp.push_back(nums[idx]);
                ret.push_back(tmp);
            }
            ret.push_back(vector<int>{nums[idx]});
            return ret;
        }
    };
}
#endif /* _8__Subsets_h */
