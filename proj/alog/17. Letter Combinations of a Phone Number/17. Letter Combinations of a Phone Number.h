//
//  17. Letter Combinations of a Phone Number.h
//  leetcode
//
//  Created by andysheng on 2021/9/21.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _7__Letter_Combinations_of_a_Phone_Number_h
#define _7__Letter_Combinations_of_a_Phone_Number_h

namespace P17 {

class Solution {
    vector<vector<string>> charTable;
public:
    Solution() {
        charTable = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"},
        };
    }
    vector<string> letterCombinations(string digits) {
        return letterCombinations(digits, 0);
    }
    vector<string> letterCombinations(string digits, int pos) {
        if (pos == digits.size()) { return vector<string>(); }
        vector<string> subRetArr = letterCombinations(digits, pos + 1);
        if (subRetArr.size() == 0) {
            return charTable[digits[pos] - '0'];
        } else {
            vector<string> ret;
            for (auto chr: charTable[digits[pos] - '0']) {
                for (auto subRet: subRetArr) {
                    ret.push_back(chr+subRet);
                }
            }
            return ret;
        }
    }
};

}
#endif /* _7__Letter_Combinations_of_a_Phone_Number_h */
