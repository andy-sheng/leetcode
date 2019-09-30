//
//  709. To Lower Case.h
//  leetcode
//
//  Created by andysheng on 2019/10/1.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _09__To_Lower_Case_h
#define _09__To_Lower_Case_h

using namespace std;

namespace ToLowerCase {
    class Solution {
    public:
        string toLowerCase(string str) {
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] = str[i] - 'A' + 'a';
                }
            }
            return str;
        }
    };
}
#endif /* _09__To_Lower_Case_h */
