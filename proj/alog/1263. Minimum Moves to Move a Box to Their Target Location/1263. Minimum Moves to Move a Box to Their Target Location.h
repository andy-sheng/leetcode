//
//  1263. Minimum Moves to Move a Box to Their Target Location.h
//  leetcode
//
//  Created by andysheng on 2020/6/2.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _263__Minimum_Moves_to_Move_a_Box_to_Their_Target_Location_h
#define _263__Minimum_Moves_to_Move_a_Box_to_Their_Target_Location_h

#include "DataStructures.h"

namespace P1263 {
    class Solution {
    public:
        int minPushBox(vector<vector<char>>& grid) {
            int ret = 0;
            
            return ret;
        }
        
        inline bool isConnected(vector<vector<char>>& grid, vector<vector<bool>>& visited, pair<int, int> boxPos, pair<int, int> playerPos, pair<int, int> targetPos) {
            bool bRet = false;
            vector<pair<int, int>> directions = {make_pair(1, 1), make_pair(-1, 1), make_pair(1, -1), make_pair(-1, -1)};
            for (auto direction: directions) {
                pair<int, int> newPos = make_pair(playerPos.first + direction.first, playerPos.second + direction.second);
                if (newPos.first < 0 || newPos.first > grid.size() || newPos.second < 0 || newPos.second > grid[0].size()) {
                    continue;
                }
                if (grid[newPos.first][newPos.second] != '#' && (newPos.first != boxPos.first || newPos.second != boxPos.second)) {
                    continue;
                }
                if (visited[newPos.first][newPos.second]) {
                    continue;
                }
                visited[newPos.first][newPos.second] = true;
                bRet = isConnected(grid, visited, boxPos, newPos, targetPos);
                if (bRet) {
                    break;
                }
            }
            return bRet;
        }
    };
}
#endif /* _263__Minimum_Moves_to_Move_a_Box_to_Their_Target_Location_h */
