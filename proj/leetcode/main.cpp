//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "532. K-diff Pairs in an Array.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {3,1,4,1,5};
    std::cout << KDiffPairsInAnArray::Solution().findPairs(input, 0) << std::endl;
    
    return 0;
}
