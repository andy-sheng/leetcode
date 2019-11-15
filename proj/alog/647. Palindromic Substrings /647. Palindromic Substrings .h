//
//  647. Palindromic Substrings .h
//  leetcode
//
//  Created by andysheng on 2019/11/16.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _47__Palindromic_Substrings__h
#define _47__Palindromic_Substrings__h
#include "DataStructures.h"
namespace PalindromicSubstring {
    class Solution {
    public:
        int countSubstrings(string s) {
            bool dp[s.size()][s.size()];
            int ret = 0;
            for (int from = s.size() - 1; from > -1; --from) {
                for (int to = from; to < s.size(); ++to) {
                    if (from == to) {
                        ++ret;
                        dp[from][to] = true;
                    } else {
                        bool subStringRet = (from + 1 < to - 1) ? dp[from + 1][to - 1] : true;
                        dp[from][to] = (s[from] == s[to]) & subStringRet;
                        ret += dp[from][to];
                    }
                }
            }
            return ret;
        }
    };
}
#endif /* _47__Palindromic_Substrings__h */
