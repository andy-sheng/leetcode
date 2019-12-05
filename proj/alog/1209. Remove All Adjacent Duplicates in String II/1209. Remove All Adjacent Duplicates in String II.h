//
//  1209. Remove All Adjacent Duplicates in String II.h
//  leetcode
//
//  Created by andysheng on 2019/12/6.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _209__Remove_All_Adjacent_Duplicates_in_String_II_h
#define _209__Remove_All_Adjacent_Duplicates_in_String_II_h

#include "DataStructures.h"

namespace P1209 {
    class Solution {
    public:
        string removeDuplicates(string s, int k) {
            stack<pair<char, int>> charStack;
            char c = -1;
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == c) {
                    ++cnt;
                } else {
                    
                    if (c != -1) {
                        //debug
                        cout << "push " << c << " " << cnt << endl;
                        //
                        charStack.push(make_pair(c, cnt));
                    }
                    c = s[i];
                    cnt = 1;
                }
                if (cnt == k) {
                    if (charStack.empty()) {
                        c = -1;
                    } else {
                        pair<char, int> lastPair = charStack.top();
                        charStack.pop();
                        c = lastPair.first;
                        cnt = lastPair.second;
                        //debug
                        cout << "pop " << c << " " << cnt << endl;
                        //
                    }
                }
            }
            string ret = "";
            while (!charStack.empty()) {
                ret = string(charStack.top().first, charStack.top().second) + ret;
                charStack.pop();
            }
            if (c != -1) {
                ret = ret + string(cnt, c);
            }
            return ret;
        }
    };
}
#endif /* _209__Remove_All_Adjacent_Duplicates_in_String_II_h */
