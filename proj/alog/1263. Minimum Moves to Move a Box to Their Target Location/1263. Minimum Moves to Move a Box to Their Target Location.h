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
            vector<vector<bool>> visited;
            pair<int, int> endPos, boxPos, playerPos;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] == 'T') {
                        endPos = make_pair(i, j);
                    } else if (grid[i][j] == 'B') {
                        boxPos = make_pair(i, j);
                    } else if (grid[i][j] == 'S') {
                        playerPos = make_pair(i, j);
                    }
                    visited[i][j] = grid[i][j] == '#' || grid[i][j] == 'B';
                }
            }
            deque<pair<int, int>> que;
            vector<pair<int, int>> possiblePushPos = possiblePushPosition(grid, boxPos);
            vector<pair<int, int>> validPushPos;
            vector<vector<bool>> tmpVisited(visited);
            getValidPushPos(grid, tmpVisited, boxPos, possiblePushPos, playerPos, validPushPos);
            
            while (que.empty()) {
                
            }
            
            return ret;
        }
        
        vector<pair<int, int>> possiblePushPosition(vector<vector<char>>& grid, pair<int, int> boxPos) {
            vector<pair<int, int>> ret;
            vector<pair<int, int>> directions = {make_pair(1, 1), make_pair(-1, 1), make_pair(1, -1), make_pair(-1, -1)};
            for (auto direction: directions) {
                pair<int, int> pushPos = make_pair(boxPos.first + direction.first, boxPos.second + direction.second);
                pair<int, int> targetPos = make_pair(boxPos.first - direction.first, boxPos.second - direction.second);
                if (isPosInsideGrid(grid, pushPos)
                    && isPosInsideGrid(grid, targetPos)
                    && grid[pushPos.first][pushPos.second] != '#'
                    && grid[targetPos.first][targetPos.second] != '#') {
                    ret.push_back(pushPos);
                }
            }
            return ret;
        }
        
        inline bool isPosInsideGrid(vector<vector<char>>& grid, pair<int, int> pos) {
            return pos.first > 0
                && pos.first < grid.size()
                && pos.second > 0
                && pos.second < grid[0].size();
        }
        
        inline void getValidPushPos(vector<vector<char>>& grid, vector<vector<bool>>& visited, pair<int, int> boxPos, vector<pair<int, int>> &playerPosArr, pair<int, int> targetPos, vector<pair<int, int>> &validPosArr) {
            vector<pair<int, int>> directions = {make_pair(1, 1), make_pair(-1, 1), make_pair(1, -1), make_pair(-1, -1)};
            for (auto direction: directions) {
                pair<int, int> newPos = make_pair(targetPos.first + direction.first, targetPos.second + direction.second);
                if (newPos.first < 0 || newPos.first > grid.size() || newPos.second < 0 || newPos.second > grid[0].size()) {
                    continue;
                }
                if (grid[newPos.first][newPos.second] == '#' || (newPos.first == boxPos.first && newPos.second == boxPos.second)) {
                    continue;
                }
                if (visited[newPos.first][newPos.second]) {
                    continue;
                }
                visited[newPos.first][newPos.second] = true;
                for (int i = 0; i < playerPosArr.size(); ++i) {
                    pair<int, int> playerPos = playerPosArr[i];
                    if (playerPos.first == newPos.first && playerPos.second == newPos.second) {
                        validPosArr.push_back(playerPos);
                        playerPosArr.erase(playerPosArr.begin() + i);
                    }
                }
                getValidPushPos(grid, visited, boxPos, playerPosArr, targetPos, validPosArr);
                if (playerPosArr.size() == 0) {
                    break;
                }
            }
        }
    };
}
#endif /* _263__Minimum_Moves_to_Move_a_Box_to_Their_Target_Location_h */
