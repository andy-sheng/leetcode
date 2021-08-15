//
//  97. Interleaving String.h
//  leetcode
//
//  Created by andysheng on 2021/8/16.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _7__Interleaving_String_h
#define _7__Interleaving_String_h
#include "DataStructures.h"
namespace P97 {

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) { return false;}
        bool ret = true;
        int s = 0, t = 0, target = 0;
        vector<vector<int>> fallbacks;
        vector<vector<bool>> tried(s1.size(), vector<bool>(s2.size(), false));
        bool tryS = false;
        while (target < s3.size()) {
            if (s3[target] == s2[t] && !tryS) {
                if (s3[target] == s1[s] && !tried[s][t]) {
                    fallbacks.push_back({target, s, t});
                    tried[s][t] = true;
                }
                ++target;
                ++t;
                tryS = false;
            } else if (s3[target] == s1[s]) {
                ++target;
                ++s;
                tryS = false;
            } else {
                if (fallbacks.empty()) {
                    ret = false;
                    break;
                } else {
                    target = fallbacks.back()[0];
                    s = fallbacks.back()[1];
                    t = fallbacks.back()[2];
                    tryS = true;
                    fallbacks.pop_back();
                }
            }
        }
        return ret;
    }
//    bool isInterleave2(string s1, string s2, string s3, int s, int t, int target) {
//        if (target == s3.size()) { return true; }
//        if (s1[s] == s3[target] && isInterleave2(s1, s2, s3, s+1, t, target+1)) {
//            return true;
//        } else if (s2[t] == s3[target] && isInterleave2(s1, s2, s3, s, t+1, target+1)) {
//            return true;
//        } else {
//            return false;
//        }
//    }
};

}

#endif /* _7__Interleaving_String_h */
