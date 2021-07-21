//
//  1409. Queries on a Permutation With Key.h
//  leetcode
//
//  Created by andysheng on 2021/7/22.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _409__Queries_on_a_Permutation_With_Key_h
#define _409__Queries_on_a_Permutation_With_Key_h

#include "DataStructures.h"

namespace P1409 {

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ret(queries.size());
        vector<int> tmp(m);
        for (int i = 0; i < m; ++i) {
            tmp[i] = i+1;
        }
        for (int i = 0; i < queries.size(); ++i) {
            auto query = queries[i];
            for (int j = 0; j < m; ++j) {
                if (tmp[j] == query) {
                    ret[i] = j;
                    tmp.erase(tmp.begin() + j);
                    tmp.insert(tmp.begin(), query);
                    break;
                }
            }
        }
        return ret;
    }
};

}
#endif /* _409__Queries_on_a_Permutation_With_Key_h */
