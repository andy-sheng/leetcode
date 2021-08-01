//
//  53. Maximum Subarray.h
//  leetcode
//
//  Created by andysheng on 2021/8/1.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Maximum_Subarray_h
#define _3__Maximum_Subarray_h

namespace P53 {

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> &sums(nums.begin(), nums.end());
        int ret = nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            if (sums[i-1] > 0) {
                sums[i] = sums[i-1] + nums[i];
            }
            ret = max(ret, sums[i]);
        }
        return ret;
    }
//    int maxSubArray(vector<int>& nums) {
//        int sum = nums.front();
//        int ret = nums.front();
//        for (int i = 1; i < nums.size(); ++i) {
//            sum = sum > 0 ? sum + nums[i] : nums[i];
//            ret = max(ret, sum);
//        }
//        return ret;
//    }
};

}
#endif /* _3__Maximum_Subarray_h */
