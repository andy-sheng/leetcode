//
//  73. Set Matrix Zeroes.h
//  leetcode
//
//  Created by andysheng on 2021/8/27.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _3__Set_Matrix_Zeroes_h
#define _3__Set_Matrix_Zeroes_h

namespace P73 {

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCnt = matrix.size();
        int colCnt = matrix[0].size();
        vector<bool> rows(rowCnt, false);
        vector<bool> cols(colCnt, false);
        for (int row = 0; row < rowCnt; ++row) {
            for (int col = 0; col < colCnt; ++col) {
                if (!rows[row]) rows[row] = matrix[row][col] == 0;
                if (!cols[col]) cols[col] = matrix[row][col] == 0;
            }
        }
        for (int row = 0; row < rowCnt; ++row) {
            for (int col = 0; col < colCnt; ++col) {
                if (rows[row] || cols[col]) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};

}

#endif /* _3__Set_Matrix_Zeroes_h */
