//
//  43. Multiply Strings.h
//  leetcode
//
//  Created by andysheng on 2021/12/18.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Multiply_Strings_h
#define _3__Multiply_Strings_h

#include "DataStructures.h"

namespace P43 {

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1Size = num1.size(), num2Size = num2.size();
        vector<vector<int>> adds(num1Size+num2Size, vector<int>());
        for (int i = 0; i < num2Size; ++i) {
            if ((num2[num2Size-i-1] - '0') == 0) {
                continue;
            }
            for (int j = 0; j < num1Size; ++j) {
                int mul = (num2[num2Size-i-1] - '0') * (num1[num1Size-j-1] - '0');
                // result
                adds[i+j].push_back(mul % 10);
                // carray
                mul = mul / 10;
                if (mul) {
                    adds[i+j+1].push_back(mul);
                }
            }
        }
        vector<int> charVec;
        for (int i = 0; i < adds.size(); ++i) {
            int tmp = 0;
            for (auto num: adds[i]) tmp += num;
            charVec.push_back(tmp % 10);
            tmp /= 10;
            int carryCnt = 0;
            while (tmp) {
                adds[i+carryCnt+1].push_back(tmp%10);
                tmp /= 10;
                ++carryCnt;
            }
        }
        string ret = "";
        bool hasNoneZero;
        for (int i = charVec.size() - 1; i > -1; --i) {
            if (!hasNoneZero) {
                hasNoneZero = charVec[i] != 0;
            }
            if (hasNoneZero) {
                ret.push_back(charVec[i]+'0');
            }
        }
        return ret.size() == 0 ? "0" : ret;
    }
};

}

#endif /* _3__Multiply_Strings_h */
