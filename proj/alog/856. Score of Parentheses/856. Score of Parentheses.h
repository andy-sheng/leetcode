//
//  856. Score of Parentheses.h
//  leetcode
//
//  Created by andysheng on 2019/11/20.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _56__Score_of_Parentheses_h
#define _56__Score_of_Parentheses_h
#include "DataStructures.h"


namespace ScoreOfParentheses {
    static int const kLeft = -1;
    class Solution {
    public:
        int scoreOfParentheses(string S) {
            vector<int> stack;
            for (char s: S) {
                if (s == ')') {
                    int tmp = 0;
                    while (stack.back() != kLeft) {
                        tmp += stack.back();
                        stack.pop_back();
                    }
                    stack.pop_back();
                    stack.push_back(tmp == 0 ? 1 : 2 * tmp);
                    cout << stack.back() << endl;
                } else {
                    stack.push_back(kLeft);
                }
            }
            int ret = 0;
            for (int i: stack) {
                ret += i;
            }
            return ret;
        }
    };
}
#endif /* _56__Score_of_Parentheses_h */
