//
//  1016. Binary String With Substrings Representing 1 To N.h
//  leetcode
//
//  Created by andysheng on 2019/11/15.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _016__Binary_String_With_Substrings_Representing_1_To_N_h
#define _016__Binary_String_With_Substrings_Representing_1_To_N_h
#include "DataStructures.h"
namespace BinaryStringWithSubstringsRepresenting1ToN {
    class Solution {
    public:
        bool queryString(string S, int N) {
            bool ret = false;
            for (int n = 1; n <= N; ++n) {
                if (S.find(toBinaryString(n)) == S.npos)
                {
                    return false;
                }
            }
            return true;
        }
        string toBinaryString(int i) {
            string ret;
            while (i) {
                ret = to_string(i & 1) + ret;
                i = i >> 1;
            }
            return ret;
        }
    };
}
#endif /* _016__Binary_String_With_Substrings_Representing_1_To_N_h */
