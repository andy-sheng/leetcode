//
//  529. Minesweeper.h
//  leetcode
//
//  Created by andysheng on 2019/12/24.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _29__Minesweeper_h
#define _29__Minesweeper_h

#include "DataStructures.h"

namespace P529 {
    class Solution {
    public:
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            deque<pair<int, int>> que {make_pair(click[0], click[1])};
            reveal2(que, board);
            return board;
        }
        
       void reveal2(deque<pair<int, int>> que, vector<vector<char>> &board) {
        vector<pair<int, int>> directions {make_pair(-1, -1),
            make_pair(-1, -1),make_pair(-1, 0),make_pair(-1, 1),
            make_pair(0, -1),make_pair(0, 1),
            make_pair(1, -1),make_pair(1, 0),make_pair(1, 1)
        };
        while (!que.empty()) {
            pair<int, int> location = que.front();
            char revealed = board[location.first][location.second];
            que.pop_front();
            if (revealed == 'M') {
                board[location.first][location.second] = 'X';
                return;
            }
            if (revealed == 'E') {
                int mineCnt = 0;
                for (auto direction : directions) {
                    int row = location.first + direction.first, col = location.second + direction.second;
                    if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
                        if (board[row][col] == 'M') {
                            ++mineCnt;
                        } else if (board[row][col]  == 'E') {
                            que.push_back(make_pair(row, col));
                        }
                    }
                }
                board[location.first][location.second] = mineCnt ? '0' + mineCnt : 'B';
            }
        }
        
        void reveal1(vector<int> location, vector<vector<char>> &board) {
            char revealed = board[location[0]][location[1]];
            if (revealed == 'M') {
                board[location[0]][location[1]] = 'X';
            } else if (revealed == 'E') {
                int mineCnt = 0;
                vector<vector<int>> directions {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
                for (auto direction : directions) {
                    int row = location[0] + direction[0], col = location[1] + direction[1];
                    if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
                        mineCnt += (board[row][col] == 'M');
                    }
                }
                if (mineCnt > 0) {
                    board[location[0]][location[1]] = '0' + mineCnt;
                } else {
                    board[location[0]][location[1]] = 'B';
                    for (auto direction : directions) {
                        int row = location[0] + direction[0], col = location[1] + direction[1];
                        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
                            reveal1(vector<int>{row, col}, board);
                        }
                    }
                }
            }
        }
    };
}
#endif /* _29__Minesweeper_h */
