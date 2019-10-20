//
//  921. Minimum Add to Make Parentheses Valid.h
//  leetcode
//
//  Created by andysheng on 2019/10/20.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _21__Minimum_Add_to_Make_Parentheses_Valid_h
#define _21__Minimum_Add_to_Make_Parentheses_Valid_h

#include <vector>

#define LEFT 0
#define RGIHT 1

using namespace std;

namespace MinimumAddToMakeParenthesesValid {
    class Solution {
    public:
        int minAddToMakeValid(string S) {
            int ret = 0;
            
            vector<bool> que;
            
            for (int i = 0; i < S.size(); ++i) {
                if (S[i] == '(') {
                    que.push_back(LEFT);
                }
                
                if (S[i] == ')') {
                    if (que.empty()) {
                        ++ret;
                    } else {
                        if (que.back() == LEFT) {
                            que.pop_back();
                        } else {
                            ++ret;
                        }
                    }
                }
            }
            ret += que.size();
            
            return ret;
        }
    };
}
#endif /* _21__Minimum_Add_to_Make_Parentheses_Valid_h */
