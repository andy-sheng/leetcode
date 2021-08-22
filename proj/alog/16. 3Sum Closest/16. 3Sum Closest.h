//
//  16. 3Sum Closest.h
//  leetcode
//
//  Created by andysheng on 2021/8/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _6__3Sum_Closest_h
#define _6__3Sum_Closest_h

namespace P16 {

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for (int xPos = 0; xPos < (int)nums.size() - 2; ++xPos) {
            if (nums[xPos] > 0 && nums[xPos] > target) break;
            if (xPos > 0 && nums[xPos] == nums[xPos-1]) continue;
            int yPos = xPos + 1;
            int zPos = nums.size() - 1;
            while (yPos < zPos) {
                int sum = nums[xPos] + nums[yPos] + nums[zPos];
                ret = abs(sum - target) < abs(ret - target) ? sum : ret;
                if (ret == target) {
                    break;
                } else if (sum > target) {
                    --zPos;
                } else {
                    ++yPos;
                }
            }
        }
        return ret;
    }
};

}
#endif /* _6__3Sum_Closest_h */
