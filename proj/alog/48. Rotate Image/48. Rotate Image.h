//
//  48. Rotate Image.h
//  leetcode
//
//  Created by andysheng on 2021/12/17.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _8__Rotate_Image_h
#define _8__Rotate_Image_h
#include "DataStructures.h"
namespace P48 {

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int tmp = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

}
#endif /* _8__Rotate_Image_h */
