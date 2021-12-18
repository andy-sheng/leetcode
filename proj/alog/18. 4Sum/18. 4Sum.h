//
//  18. 4Sum.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _8__4Sum_h
#define _8__4Sum_h

namespace P18 {

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3;) {
            for (int j = i + 1; j < size - 2;) {
                int target2 = target - nums[i] - nums[j];
                int front = j + 1, back = size - 1;
                while (front < back) {
                    int sum = nums[front] + nums[back];
                    if (sum >= target2) {
                        if (sum == target2) {
                            ret.push_back({nums[i], nums[j], nums[front], nums[back]});
                        }
                        --back;
                        while (back > front && nums[back] == nums[back+1]) --back;
                    } else {
                        ++front;
                        while (back > front && nums[front] == nums[front-1]) ++front;
                    }
                }
                ++j;
                while (j < size - 2 && nums[j] == nums[j-1]) ++j;
            }
            ++i;
            while (i < size - 3 && nums[i] == nums[i-1]) ++i;
        }
        return ret;
    }
};

}

#endif /* _8__4Sum_h */
