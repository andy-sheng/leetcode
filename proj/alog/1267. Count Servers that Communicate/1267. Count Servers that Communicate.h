//
//  1267. Count Servers that Communicate.h
//  leetcode
//
//  Created by andysheng on 2019/11/26.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _267__Count_Servers_that_Communicate_h
#define _267__Count_Servers_that_Communicate_h

namespace P1267 {
    class Solution {
    public:
        int countServers(vector<vector<int>>& grid) {
            vector<short> rows(grid.size(), -1);
            vector<short> cols(grid[0].size(), -1);

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j]) {
                        ++rows[i];
                        ++cols[j];
                    }
                }
            }
            int ret = 0;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] && (rows[i] > 0 || cols[j] > 0)) {
                        ++ret;
                    }
                }
            }
            return ret;
        }
    };
}
#endif /* _267__Count_Servers_that_Communicate_h */
