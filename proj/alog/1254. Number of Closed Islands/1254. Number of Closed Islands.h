//
//  1254. Number of Closed Islands.h
//  leetcode
//
//  Created by andysheng on 2019/11/12.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _254__Number_of_Closed_Islands_h
#define _254__Number_of_Closed_Islands_h
#include "DataStructures.h"
namespace NUmberOfClosedIsland {
    class Solution {
    public:
        int closedIsland(vector<vector<int>>& grid) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[0][col] == 0) {
                    markLand(grid, 0, col);
                }
                if (grid[grid.size() - 1][col] == 0) {
                    markLand(grid, grid.size() - 1, col);
                }
            }
            for (int row = 0; row < grid.size(); ++ row) {
                if (grid[row][0] == 0) {
                    markLand(grid, row, 0);
                }
                if (grid[row][grid[0].size() - 1] == 0) {
                    markLand(grid, row, grid[0].size() - 1);
                }
            }
            int ret = 0;
            for (int row = 1; row < grid.size() - 1; ++row) {
                for (int col = 1; col < grid[0].size() - 1; ++col) {
                    if (grid[row][col] == 0) {
                        ++ret;
                        markLand(grid, row, col);
                    }
                }
            }
            return ret;
        }

        void markLand(vector<vector<int>>& grid, int x, int y) {
            int area = 1;
            grid[x][y] = 2;

            if (x - 1 > -1 && grid[x - 1][y] == 0) {
                markLand(grid, x - 1, y);
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 0) {
                markLand(grid, x, y + 1);
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == 0) {
                markLand(grid, x + 1, y);
            }
            if (y - 1 > -1 && grid[x][y - 1] == 0) {
                markLand(grid, x, y - 1);
            }
        }
    };
}
#endif /* _254__Number_of_Closed_Islands_h */
