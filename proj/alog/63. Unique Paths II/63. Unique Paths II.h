//
//  63. Unique Paths II.h
//  leetcode
//
//  Created by andysheng on 2021/9/11.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Unique_Paths_II_h
#define _3__Unique_Paths_II_h

namespace P63 {

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowCount = obstacleGrid.size(), colCount = obstacleGrid[0].size();
        vector<int> lastRow(colCount);
        lastRow[0] = obstacleGrid[0][0] != 1;
        for (int i = 1; i < colCount; ++i) {
            lastRow[i] = obstacleGrid[0][i] == 1 ? 0 : lastRow[i-1];
        }
        for (int row = 1; row < rowCount; ++row) {
            if (obstacleGrid[row][0] == 1) { lastRow[0] = 0; }
            for (int col = 1; col < colCount; ++col) {
                lastRow[col] = obstacleGrid[row][col] == 1 ? 0 : lastRow[col - 1] + lastRow[col];
            }
        }
        return lastRow.back();
    }
};

}

#endif /* _3__Unique_Paths_II_h */
