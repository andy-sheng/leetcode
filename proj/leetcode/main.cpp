//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "69. Sqrt(x).h"
#include <math.h>

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10000; ++i) {
        int a = Sqrt::Solution().mySqrt(i);
        int b = sqrt(i);
        if (a != b) {
            std::cout << "i:"<<i<<" a:" <<a<<" b:"<<b  << std::endl;
        }
    }
    
//    std::cout << Sqrt::Solution().mySqrt(1) << std::endl;
    
    
    
    return 0;
}
