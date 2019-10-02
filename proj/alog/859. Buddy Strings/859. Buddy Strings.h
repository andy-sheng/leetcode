//
//  859. Buddy Stringss.h
//  leetcode
//
//  Created by andysheng on 2019/10/3.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _93__Valid_Phone_Numbers_h
#define _93__Valid_Phone_Numbers_h

using namespace std;

namespace BuddyStrings {
    class Solution {
    public:
        bool buddyStrings(string A, string B) {
            if (A.size() != B.size()) {
                return false;
            }
            
            short letterCnt[26] = {0};
            char letterInA = ' ';
            char letterInB = ' ';
            int diffCnt = 0;
            bool ret = false;
            bool hasDuplicateLetter = false;
            for (int i = 0; i < A.size(); ++i) {
                ++letterCnt[A[i] - 'a'];
                
                if (letterCnt[A[i] - 'a'] > 1 && !hasDuplicateLetter) {
                    hasDuplicateLetter = true;
                }
                
                if (A[i] != B[i]) {
                    ++diffCnt;
                    if (diffCnt == 1) {
                        letterInA = A[i];
                        letterInB = B[i];
                    } else if (diffCnt == 2) {
                        ret = (letterInA == B[i]) && (letterInB == A[i]);
                    } else {
                        ret = false;
                        break;
                    }
                }
            }
            
            if (!ret && diffCnt == 0) {
                ret = hasDuplicateLetter;
            }
            
            return ret;
        }
    };
}

#endif /* _93__Valid_Phone_Numbers_h */
