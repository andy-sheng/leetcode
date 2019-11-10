//
//  695. Max Area of Island.h
//  leetcode
//
//  Created by andysheng on 2019/11/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _95__Max_Area_of_Island_h
#define _95__Max_Area_of_Island_h

#include "DataStructures.h"

namespace MaxAreaOfIsland {
    class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ret = 0;
            for (int row = 0; row < grid.size(); ++row) {
                for (int col = 0; col < grid[0].size(); ++col) {
                    if (grid[row][col] == 1) {
                        int area = countAreaAndMark(grid, row, col);
                        ret = max(ret, area);
                    }
                }
            }
            return ret;
        }
        
        int countAreaAndMark(vector<vector<int>>& grid, int x, int y) {
            int area = 1;
            grid[x][y] = 2;
            
            if (x - 1 > -1 && grid[x - 1][y] == 1) {
                area += countAreaAndMark(grid, x - 1, y);
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                area += countAreaAndMark(grid, x, y + 1);
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                area += countAreaAndMark(grid, x + 1, y);
            }
            if (y - 1 > -1 && grid[x][y - 1] == 1) {
                area += countAreaAndMark(grid, x, y - 1);
            }
            
            return area;
        }
    };
}
#endif /* _95__Max_Area_of_Island_h */
