//
//  1023. Camelcase Matching.h
//  leetcode
//
//  Created by andysheng on 2019/12/27.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _023__Camelcase_Matching_h
#define _023__Camelcase_Matching_h

namespace P1023 {
    class Solution {
    public:
        vector<bool> camelMatch(vector<string>& queries, string pattern) {
            vector<bool> ret;
            for (auto query: queries) {
                bool flag = true;
                int i = 0, j = 0;
                while (i < query.size() && j < pattern.size()) {
                    if (query[i] == pattern[j]) {
                        ++i;
                        ++j;
                    } else if (query[i] <= 'z' && query[i] >= 'a') {
                        ++i;
                    } else {
                        flag = false;
                        break;
                    }
                }
                flag = flag & (j == pattern.size());
                while (flag && i < query.size()) {
                    if (query[i++] <= 'Z') {
                        flag = false;
                    }
                }
                ret.push_back(flag);
            }
            return ret;
        }
    };
}
#endif /* _023__Camelcase_Matching_h */
