//
//  1190. Reverse Substrings Between Each Pair of Parentheses.h
//  leetcode
//
//  Created by andysheng on 2019/11/24.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _190__Reverse_Substrings_Between_Each_Pair_of_Parentheses_h
#define _190__Reverse_Substrings_Between_Each_Pair_of_Parentheses_h

#include "DataStructures.h"

namespace P1190 {
    class Solution {
    public:
        string reverseParentheses(string s) {
            string ret;
            
            vector<char> stack;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == ')') {
                    int j = stack.size() - 1;
                    while (stack[j] != '(') --j;
                    reverse(stack.begin() + j + 1, stack.end());
                    stack.erase(stack.begin() + j);
                } else {
                    stack.push_back(s[i]);
                }
            }
            
            return string(stack.begin(), stack.end());
        }
    };
}
#endif /* _190__Reverse_Substrings_Between_Each_Pair_of_Parentheses_h */
