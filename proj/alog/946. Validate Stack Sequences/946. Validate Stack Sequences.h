//
//  946. Validate Stack Sequences.h
//  leetcode
//
//  Created by andysheng on 2019/11/16.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _46__Validate_Stack_Sequences_h
#define _46__Validate_Stack_Sequences_h
#include "DataStructures.h"
namespace ValidateStackSequences {
    class Solution {
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            if (pushed.size() != popped.size()) return false;
            int idxPushed = 0, idxPopped = 0;
            vector<int> stack;
            while (idxPopped < popped.size()) {
                while (idxPushed < pushed.size() && (stack.empty() || stack.back() != popped[idxPopped])) {
                    stack.push_back(pushed[idxPushed++]);
                }
                if (stack.back() == popped[idxPopped]) {
                    stack.pop_back();
                    ++idxPopped;
                } else {
                    break;
                }
            }
            return stack.empty();
        }
    };
}
#endif /* _46__Validate_Stack_Sequences_h */
