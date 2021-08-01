//
//  200. Number of Islands.h
//  leetcode
//
//  Created by andysheng on 2021/8/1.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _00__Number_of_Islands_h
#define _00__Number_of_Islands_h

namespace P200 {

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[0].size(); ++y) {
                if (grid[x][y] == '1') {
                    ++ret;
                    dfs(grid, x, y);
                }
            }
        }
        return ret;
    }
    inline void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        vector<vector<int>> directions = {{0,1}, {0,-1}, {-1,0},{1,0}};
        for (auto direction: directions) {
            int newX = x + direction[0];
            int newY = y + direction[1];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1') {
                dfs(grid, newX, newY);
            }
        }
    }
};

}
#endif /* _00__Number_of_Islands_h */
