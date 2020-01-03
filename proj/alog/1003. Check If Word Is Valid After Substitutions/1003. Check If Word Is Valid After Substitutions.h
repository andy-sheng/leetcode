//
//  1003. Check If Word Is Valid After Substitutions.h
//  leetcode
//
//  Created by andysheng on 2020/1/4.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _003__Check_If_Word_Is_Valid_After_Substitutions_h
#define _003__Check_If_Word_Is_Valid_After_Substitutions_h

#include "DataStructures.h"

namespace P1003 {
    class Solution {
    public:
        bool isValid(string S) {
            stack<char> s;
            for (char c : S) {
                if (c == 'c') {
                    vector<char> delChars {'a', 'b'};
                    while (!delChars.empty() && !s.empty() && s.top() == delChars.back()) {
                        delChars.pop_back();
                        s.pop();
                    }
                    if (!delChars.empty()) {
                        return false;
                    }
                } else {
                    s.push(c);
                }
            }
            return s.empty();
        }
    };
}
#endif /* _003__Check_If_Word_Is_Valid_After_Substitutions_h */
