//
//  526. Beautiful Arrangement.h
//  leetcode
//
//  Created by andysheng on 2019/12/9.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _26__Beautiful_Arrangement_h
#define _26__Beautiful_Arrangement_h

#include "DataStructures.h"

namespace P526 {
    class Solution {
    public:
        int countArrangement(int N) {
            unordered_map<int, vector<int>> divisibleNums(16);
            for (int i = 1; i <= N; ++i) {
                divisibleNums[i] = vector<int>();
                for (int j = 1; j <= N; ++j) {
                    if (i % j == 0 || j % i == 0) {
                        divisibleNums[i].push_back(j);
                    }
                }
            }
            
            // debug
            for (int i = 1; i <= N; ++i) {
                for (int j: divisibleNums[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
            
            int ret = 0;
            bool used[N+1];
            memset(used, 0, sizeof(bool) * (N + 1));
            
            arrange(divisibleNums, used, N, ret);
            
            
            return ret;
        }
        
        void arrange(unordered_map<int, vector<int>> &divisibleNums, bool used[], int idx, int &cnt) {
            for (auto i: divisibleNums[idx]) {
                if (idx == 1) {
                    if (!used[i]) {
                        ++cnt;
                    }
                } else {
                    if (!used[i]) {
                        used[i] = true;
                        arrange(divisibleNums, used, idx - 1, cnt);
                        used[i] = false;
                    }
                }
            }
        }
    };
}
#endif /* _26__Beautiful_Arrangement_h */
