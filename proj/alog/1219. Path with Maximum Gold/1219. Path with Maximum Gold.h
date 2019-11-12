//
//  1219. Path with Maximum Gold.h
//  leetcode
//
//  Created by andysheng on 2019/11/13.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _219__Path_with_Maximum_Gold_h
#define _219__Path_with_Maximum_Gold_h
#include "DataStructures.h"
namespace PathWithMaximumGold {
    class Solution {
    public:
        int getMaximumGold(vector<vector<int>>& grid) {
            int ret = 0;
            for (int row = 0; row < grid.size(); ++row) {
                for (int col = 0; col < grid[0].size(); ++col) {
                    if (grid[row][col]) {
                        ret = max(ret, getMaxmumGold(grid, row, col));
                    }
                }
            }
            return ret;
        }
        int getMaxmumGold(vector<vector<int>>& grid, int x, int y) {
            int ret = 0;
            int tmp = grid[x][y];
            grid[x][y] = 0;
            if (x - 1 > -1 && grid[x - 1][y]) {
                ret = max(ret, getMaxmumGold(grid, x - 1, y));
            }
            if (x + 1 < grid.size() && grid[x + 1][y]) {
                ret = max(ret, getMaxmumGold(grid, x + 1, y));
            }
            if (y - 1 > -1 && grid[x][y - 1]) {
                ret = max(ret, getMaxmumGold(grid, x, y - 1));
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1]) {
                ret = max(ret, getMaxmumGold(grid, x, y + 1));
            }
            grid[x][y] = tmp;
            return ret + tmp;
        }
    };
}
#endif /* _219__Path_with_Maximum_Gold_h */
