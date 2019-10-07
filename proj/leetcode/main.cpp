//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "581. Shortest Unsorted Continuous Subarray.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {2,1};
    std::cout << ShortestUnsortedContinuousSubarray::Solution().findUnsortedSubarray(input) << std::endl;
    
    return 0;
}
