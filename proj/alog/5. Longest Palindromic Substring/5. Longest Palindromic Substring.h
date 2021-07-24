//
//  5. Longest Palindromic Substring.h
//  leetcode
//
//  Created by andysheng on 2021/7/24.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef ___Longest_Palindromic_Substring_h
#define ___Longest_Palindromic_Substring_h

#include "DataStructures.h"

namespace P5 {

#include "DataStructures.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = (int)s.size();
        for (; length > 1; --length) {
            for (int i = 0, j = i + length - 1; i < j && j < s.size() ; ++i, j = i + length - 1) {
                int n = i, m = j;
                while (n < m && s[n] == s[m]) {
                    ++n;
                    --m;
                }
                if (n >= m) {
                    return s.substr(i, length);
                }
            }
        }
        return s.substr(0,1);
    }
};

}
#endif /* ___Longest_Palindromic_Substring_h */
