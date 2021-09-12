//
//  79. Word Search.h
//  leetcode
//
//  Created by andysheng on 2021/9/12.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _9__Word_Search_h
#define _9__Word_Search_h
#include "DataStructures.h"
namespace P79 {

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int rowCount = board.size(), colCount = board[0].size();
        for (int x = 0; x < rowCount; ++x) {
            for (int y = 0; y < colCount; ++y) {
                if (dfs(board, visited, x, y, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string word, int pos) {
        if (pos == word.size()) { return true; }
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size()) { return false; }
        if (board[x][y] != word[pos] || visited[x][y]) { return false; }
        visited[x][y] = true;
        if (dfs(board, visited, x, y + 1, word, pos + 1)) {
            return true;
        }
        if (dfs(board, visited, x, y - 1, word, pos + 1)) {
            return true;
        }
        if (dfs(board, visited, x + 1, y, word, pos + 1)) {
            return true;
        }
        if (dfs(board, visited, x - 1, y, word, pos + 1)) {
            return true;
        }
        visited[x][y] = false;
        return false;
    }
};

}
#endif /* _9__Word_Search_h */
