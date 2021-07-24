//
//  3. Longest Substring Without Repeating Characters.h
//  leetcode
//
//  Created by andysheng on 2021/7/23.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef ___Longest_Substring_Without_Repeating_Characters_h
#define ___Longest_Substring_Without_Repeating_Characters_h

#include "DataStructures.h"

namespace P3 {

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        if (s.size() == 0) { return 0; }
        
        vector<int> map(256, -1);
        int lower = 0, upper = 1;
        map[s[0]] = 0;
        for (; upper < s.size(); ++upper) {
            if (map[s[upper]] != -1) {
                ret = max(ret, upper - lower);
                while (lower < map[s[upper]]) {
                    map[s[lower]] = -1;
                    ++lower;
                }
                ++lower;
            }
            map[s[upper]] = upper;
        }
        return max(ret, upper - lower);
    }
};

}

#endif /* ___Longest_Substring_Without_Repeating_Characters_h */
