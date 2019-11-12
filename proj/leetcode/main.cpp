//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1219. Path with Maximum Gold.h"

int main(int argc, const char * argv[]) {
    vector<vector<int>> input {{0,6,0},{5,8,7},{0,9,0}};
    cout << PathWithMaximumGold::Solution().getMaximumGold(input) <<endl;
    return 0;
}
