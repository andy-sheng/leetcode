//
//  45. Jump Game II.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _5__Jump_Game_II_h
#define _5__Jump_Game_II_h

namespace P45 {

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ret = 1, pos = 0, size = nums.size();
        vector<int> nextPos(size, 0);
        for (int i = 0; i < size; ++i) {
            nextPos[i] = nums[i] + i;
        }
        while (nextPos[pos] < size - 1) {
            int max = nextPos[pos], j = nextPos[pos];
            for (int i = pos + 1; i <= nextPos[pos] && i < size; ++i) {
                if (nextPos[i] > max) {
                    max = nextPos[i];
                    j = i;
                }
            }
            pos = j;
            ++ret;
        }
        return ret;
    }
};


}
#endif /* _5__Jump_Game_II_h */
