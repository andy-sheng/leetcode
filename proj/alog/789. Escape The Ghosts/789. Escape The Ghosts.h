//
//  789. Escape The Ghosts.h
//  leetcode
//
//  Created by andysheng on 2019/12/9.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _89__Escape_The_Ghosts_h
#define _89__Escape_The_Ghosts_h

namespace P789 {
    class Solution {
    public:
        bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
            int dis = abs(target[0]) + abs(target[1]);
            for (auto ghost: ghosts) {
                if (abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]) <= dis) {
                    return false;
                }
            }
            return true;
        }
    };
}

#endif /* _89__Escape_The_Ghosts_h */
