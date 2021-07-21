//
//  1329. Sort the Matrix Diagonally.h
//  leetcode
//
//  Created by andysheng on 2021/7/22.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _329__Sort_the_Matrix_Diagonally_h
#define _329__Sort_the_Matrix_Diagonally_h

#include "DataStructures.h"

namespace P1329 {

inline pair<int, int> findBottomRight(pair<int, int> point, int rowCnt, int colCnt) {
    int diff = min(rowCnt - point.first, colCnt - point.second);
    return make_pair(point.first + diff - 1, point.second + diff - 1);
}

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rowCnt = (int)mat.size();
        int colCnt = (int)mat[0].size();
        for (int row = 0; row < rowCnt - 1; ++row) {
            pair<int, int> topLeft = make_pair(row, 0);
            mergeSort(mat, topLeft, findBottomRight(topLeft, rowCnt, colCnt));
        }
        for (int col = 1; col < colCnt - 1; ++col) {
            pair<int, int> topLeft = make_pair(0, col);
            mergeSort(mat, topLeft, findBottomRight(topLeft, rowCnt, colCnt));
        }
        return mat;
    }
    
    void mergeSort(vector<vector<int>>& mat, pair<int, int> begin, pair<int, int> end) {
        if (begin.first >= end.first) return;
        pair<int, int> mid = make_pair((begin.first + end.first) / 2, (begin.second + end.second) / 2);
        mergeSort(mat, begin, mid);
    
        mergeSort(mat, make_pair(mid.first + 1, mid.second + 1), end);
        
        vector<int> tmp(end.first - begin.first + 1);
        pair<int, int> i = begin;
        pair<int, int> j = make_pair(mid.first + 1, mid.second + 1);
        int n = 0;
        while (i.first <= mid.first && j.first <= end.first) {
            if (mat[i.first][i.second] < mat[j.first][j.second]) {
                tmp[n++] = mat[i.first][i.second];
                i.first += 1;
                i.second += 1;
            } else {
                tmp[n++] = mat[j.first][j.second];
                j.first += 1;
                j.second += 1;
            }
        }
        while (i.first <= mid.first) {
            tmp[n++] = mat[i.first][i.second];
            i.first += 1;
            i.second += 1;
        }
        while (j <= end) {
            tmp[n++] = mat[j.first][j.second];
            j.first += 1;
            j.second += 1;
        }
        for (int n = begin.first, m = begin.second; n <= end.first; ++n, ++m) {
            mat[n][m] = tmp[n-begin.first];
        }
    }
};

}

#endif /* _329__Sort_the_Matrix_Diagonally_h */
