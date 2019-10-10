//
//  807. Max Increase to Keep City Skyline.h
//  leetcode
//
//  Created by andysheng on 2019/10/11.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _07__Max_Increase_to_Keep_City_Skyline_h
#define _07__Max_Increase_to_Keep_City_Skyline_h

#include <vector>

using namespace std;
namespace MaxIncreaseToKeepCitySkyline {
    class Solution {
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
            int ret = 0;
            if (grid.size() == 0) return ret;
            
            vector<int> skylineFromTop(grid[1].size(), 0);
            vector<int> skylineFromLeft(grid.size(), 0);
            
            for (int row = 0; row < grid.size(); ++row) {
                for (int col = 0; col < grid[0].size(); ++col) {
                    if (grid[row][col] > skylineFromTop[col]) {
                        skylineFromTop[col] = grid[row][col];
                    }
                    
                    if (grid[row][col] > skylineFromLeft[row]) {
                        skylineFromLeft[row] = grid[row][col];
                    }
                }
            }
            
   
            for (int row = 0; row < grid.size(); ++row) {
                for (int col = 0; col < grid[0].size(); ++col) {
                    
                    int maxHeight = skylineFromTop[col] < skylineFromLeft[row] ? skylineFromTop[col] :skylineFromLeft[row];
                    
                    ret += maxHeight - grid[row][col];
                }
            }
            
            return ret;
        }
    };
}

#endif /* _07__Max_Increase_to_Keep_City_Skyline_h */
