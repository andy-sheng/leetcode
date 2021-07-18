//
//  1476. Subrectangle Queries.h
//  leetcode
//
//  Created by andysheng on 2021/7/19.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef _476__Subrectangle_Queries_h
#define _476__Subrectangle_Queries_h

#include <vector>

namespace P1276 {

using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> data;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        data = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                data[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return data[row][col];
    }
};

class SubrectangleQueries2 {
private:
    vector<vector<int>> data;
    vector<vector<int>> updates;
public:
    SubrectangleQueries2(vector<vector<int>>& rectangle) {
        data = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (int idx = updates.size() - 1; idx > -1; --idx) {
            vector<int> update = updates[i];
            if (row >= update[0]
                && col >= update[1]
                && row <= update[2]
                && col <= update[3]) {
                return update[4];
            }
        }
        return data[row][col];
    }
};


}

#endif /* _476__Subrectangle_Queries_h */
