//
//  1249. Minimum Remove to Make Valid Parentheses.h
//  leetcode
//
//  Created by andysheng on 2019/11/15.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _249__Minimum_Remove_to_Make_Valid_Parentheses_h
#define _249__Minimum_Remove_to_Make_Valid_Parentheses_h

#include "DataStructures.h"

namespace MinimumRemoveToMakeValidParentheses {
    class Solution {
    public:
        string minRemoveToMakeValid(string s) {
            vector<int> stack;
            for (int i = 0; i < s.size(); ++i) {
                if (!stack.empty() && s[stack.back()] == '(' && s[i] == ')') {
                    s[stack.back()] = '(';
                    stack.pop_back();
                } else if (s[i] == '(' || s[i] == ')') {
                    stack.push_back(i);
                }
            }
            while (!stack.empty()) {
                s.erase(s.begin() + stack.back());
                stack.pop_back();
            }
         
            return s;
        }
    };
    class Solution2 {
    public:
        string minRemoveToMakeValid(string s) {
            vector<int> stack;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == ')') {
                    if (stack.empty()) {
                        s[i] = 0;
                    } else {
                        s[stack.back()] = '(';
                        stack.pop_back();
                    }
                } else if (s[i] == '(') {
                    s[i] = 0;
                    stack.push_back(i);
                }
            }
            s.erase(remove(s.begin(), s.end(), 0), end(s));
            return s;
        }
    };
}
#endif /* _249__Minimum_Remove_to_Make_Valid_Parentheses_h */
