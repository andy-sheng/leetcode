//
//  1072. Flip Columns For Maximum Number of Equal Rows.h
//  leetcode
//
//  Created by andysheng on 2019/11/11.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _072__Flip_Columns_For_Maximum_Number_of_Equal_Rows_h
#define _072__Flip_Columns_For_Maximum_Number_of_Equal_Rows_h

#include "DataStructures.h"

namespace FlipColumnsForMaximumNumberOfEqualRows {
    class Solution {
    public:
        int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
            unordered_map<string, int> cnt;
            for (vector<int> row : matrix) {
                string tmp(row.size(), ' ');
                string reverse(row.size(), ' ');
                for (int i = 0; i < row.size(); ++i) {
                    tmp[i] = row[i] == 1 ? '1' : '0';
                    reverse[i] = row[i] == 1 ? '0' : '1';
                }
                ++cnt[tmp];
                ++cnt[reverse];
            }
            int ret = -1;
            for (unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
                ret = max(ret, it->second);
            }
            return ret;
        }
    };
}
#endif /* _072__Flip_Columns_For_Maximum_Number_of_Equal_Rows_h */
