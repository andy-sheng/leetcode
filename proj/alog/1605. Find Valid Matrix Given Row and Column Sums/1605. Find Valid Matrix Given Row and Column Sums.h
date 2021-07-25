//
//  1605. Find Valid Matrix Given Row and Column Sums.h
//  leetcode
//
//  Created by andysheng on 2021/7/25.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _605__Find_Valid_Matrix_Given_Row_and_Column_Sums_h
#define _605__Find_Valid_Matrix_Given_Row_and_Column_Sums_h

#include "DataStructures.h"

namespace P1605 {

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ret(rowSum.size(), vector<int>(colSum.size(), 0));
        tryFit(0, 0, ret, rowSum, colSum);
        return ret;
    }
    bool tryFit(int i, int j, vector<vector<int>>& ret, vector<int>& rowSum, vector<int>& colSum) {
        int itemIJMax = min(rowSum[i], colSum[j]);
        int nextI = i, nextJ = j;
        if (i == rowSum.size() - 1 && j == colSum.size() - 1) {
            if (rowSum[i] == colSum[j]) {
                ret[i][j] = rowSum[i];
                return true;
            } else {
                return false;
            }
        } else if (i == rowSum.size() - 1) {
            itemIJMax = colSum[j];
        } else if (j == colSum.size() - 1) {
            itemIJMax = rowSum[i];
            nextI++;
        }
        nextJ = (j + 1) % colSum.size();

        for (int tryNum = itemIJMax; tryNum > -1; --tryNum) {
            cout << i <<"-"<<j<<"try "<<tryNum<<endl;

            rowSum[i] -= tryNum;
            colSum[j] -= tryNum;
            if (tryFit(nextI, nextJ, ret, rowSum, colSum)) {
                ret[i][j] = tryNum;
                return true;
            }
            rowSum[i] += tryNum;
            colSum[j] += tryNum;
        }
        
        return false;
    }
};

}
#endif /* _605__Find_Valid_Matrix_Given_Row_and_Column_Sums_h */
