//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "861. Score After Flipping Matrix.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> input {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    
    cout << ScoreAfterFlippingMatrix::Solution().matrixScore(input) << endl;
    
    return 0;
}
