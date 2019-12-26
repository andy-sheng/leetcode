//
//  1020. Number of Enclaves.h
//  leetcode
//
//  Created by andysheng on 2019/12/27.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _020__Number_of_Enclaves_h
#define _020__Number_of_Enclaves_h

#include "DataStructures.h"

namespace P1020 {
    class Solution {
    public:
        int numEnclaves(vector<vector<int>>& A) {
            for (int col = 0; col < A[0].size(); ++col) {
                if (A[0][col]) mark(A, make_pair(0, col));
                if (A[A.size() - 1][col]) mark(A, make_pair(A.size() - 1, col));
            }
            for (int row = 0; row < A.size(); ++row) {
                if (A[row][0]) mark(A, make_pair(row, 0));
                if (A[row][A[0].size() - 1]) mark(A, make_pair(row, A[0].size() - 1));
            }
            int ret = 0;
            for (auto row : A) {
                for (auto col : row) {
                    if (col) ++ret;
                }
            }
            return ret;
        }
        
        void mark(vector<vector<int>>& A, pair<int, int> pos) {
            if (!A[pos.first][pos.second]) {
                return;
            }
            A[pos.first][pos.second] = 0;
            vector<pair<int, int>> directions {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
            for (auto direction : directions) {
                int row = pos.first + direction.first;
                int col = pos.second + direction.second;
                if (row >= 0 && row < A.size() && col >= 0 && col < A[0].size() && A[row][col]) {
                    mark(A, make_pair(row, col));
                }
            }
        }
        
        int numEnclaves_unionfind(vector<vector<int>>& A) {
            Algorithm::UnionFind unionFind(A.size() * A[0].size() + 1);
            int landCnt = 0;
            for (int row = 0; row < A.size(); ++row) {
                for (int col = 0; col < A[0].size(); ++col) {
                    int pos = row * A[0].size() + col + 1;
                    if (A[row][col]) {
                        ++landCnt;
                        if (row == 0 || row == A.size() - 1 || col == 0 || col == A[0].size() - 1) {
                            unionFind.Union(pos, 0);
                        }
                        if (row > 0 && A[row - 1][col]) {
                            unionFind.Union(pos, pos - A[0].size());
                        }
                        if (col > 0 && A[row][col - 1]) {
                            unionFind.Union(pos, pos - 1);
                        }
                    }
                }
            }
            return landCnt - unionFind.getRank(unionFind.find(0)) + 1;
        }
    };
}
#endif /* _020__Number_of_Enclaves_h */
