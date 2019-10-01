//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "665. Non-decreasing Array.h"
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> values {4,2,3};
    
    std::cout << NonDecreasingArray::Solution().checkPossibility(values) << std::endl;
    
    
    return 0;
}
