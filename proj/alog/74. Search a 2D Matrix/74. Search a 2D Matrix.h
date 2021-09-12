//
//  74. Search a 2D Matrix.h
//  leetcode
//
//  Created by andysheng on 2021/9/12.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _4__Search_a_2D_Matrix_h
#define _4__Search_a_2D_Matrix_h

namespace P74 {

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        int col = findCol(matrix[row], target);
        return col > -1;
    }
    
    int findRow(vector<vector<int>>& matrix, int target) {
        int rowCnt = matrix.size();
        int low = 0, high = rowCnt - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                if (low == mid) {
                    if (target >= matrix[high][0]) low = high; else high = low;
                    break;
                } else {
                    low = mid;
                }
            }
        }
        return low;
    }
    
    int findCol(vector<int>& row, int target) {
        int low = 0; int high = row.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (row[mid] == target) {
                return mid;
            } else if (row[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

}
#endif /* _4__Search_a_2D_Matrix_h */
