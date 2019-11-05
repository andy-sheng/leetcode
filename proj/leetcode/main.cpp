//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "973. K Closest Points to Origin.h"

int main(int argc, const char * argv[]) {
    vector<vector<int>> input {{6,-7},{-9,-3},{10,6},{-5,-8},{-4,-10},{-3,-10},{2,-4}};
    KClosestPointsToOrigin::Solution().kClosest(input, 6);
    return 0;
}
