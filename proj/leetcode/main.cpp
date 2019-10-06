//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "605. Can Place Flowers.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {1,0,0,0,1,0,0};
    std::cout << CanPlaceFlowers::Solution().canPlaceFlowers(input, 1) << std::endl;
    
    return 0;
}
