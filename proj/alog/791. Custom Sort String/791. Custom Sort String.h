//
//  791. Custom Sort String.h
//  leetcode
//
//  Created by andysheng on 2019/11/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _91__Custom_Sort_String_h
#define _91__Custom_Sort_String_h
#include <algorithm>
using namespace std;

short location[26];

bool cmp(char a, char b) {
    if (location[a - 'a'] == -1) {
        return false;
    }
    if (location[b - 'a'] == -1) {
        return true;
    }
    return location[a - 'a'] < location[b - 'a'];
}

namespace CustomSortString {
    class Solution {
    public:
        string customSortString(string S, string T) {
            memset(location, -1, sizeof(short) * 26);
            for (int i = 0; i < S.size(); ++i) {
                if (location[S[i] - 'a']) {
                    location[S[i] - 'a'] = i;
                }
            }
            sort(T.begin(), T.end(), cmp);
            return T;
        }
    };
}
#endif /* _91__Custom_Sort_String_h */
