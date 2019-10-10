//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "807. Max Increase to Keep City Skyline.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> grid {{3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0}};
    cout << MaxIncreaseToKeepCitySkyline::Solution().maxIncreaseKeepingSkyline(grid) << endl;
    
    
    
    return 0;
}
