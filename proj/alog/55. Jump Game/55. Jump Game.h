//
//  55. Jump Game.h
//  leetcode
//
//  Created by andysheng on 2021/9/19.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _5__Jump_Game_h
#define _5__Jump_Game_h

namespace P55 {


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDistance = 0, numsCnt = nums.size();
        for (int i = 0; i < numsCnt; ++i) {
            if (maxDistance < i) {
                return false;
            } else {
                maxDistance = max(maxDistance, i + nums[i]);
            }
        }
        return maxDistance >= numsCnt - 1;
    }
//    bool canJump(vector<int>& nums) {
//        vector<bool> canJump(nums.size(), false);
//        canJump[nums.size() - 1] = true;
//        for (int i = nums.size() - 2; i > -1; --i) {
//            int searchEnd = min((int)(nums.size() - 1), i + nums[i]);
//            for (int j = i + 1; j <= searchEnd; ++j) {
//                if (canJump[j]) {
//                    canJump[i] = true;
//                    break;
//                }
//            }
//        }
//        return canJump.front();
//    }
};

}
#endif /* _5__Jump_Game_h */
