//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "639. Decode Ways II.h"

int main(int argc, const char * argv[]) {

    cout << P639::Solution().numDecodings("226") <<endl;
    cout << P639::Solution().numDecodings("12") <<endl;
    cout << P639::Solution().numDecodings("0") <<endl;
    cout << P639::Solution().numDecodings("06") <<endl;
    cout << P639::Solution().numDecodings("*") <<endl;
    cout << P639::Solution().numDecodings("1*") <<endl;
    cout << P639::Solution().numDecodings("2*") <<endl;
    cout << P639::Solution().numDecodings("*********") <<endl;
    
    return 0;
}
