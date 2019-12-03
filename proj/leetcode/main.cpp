//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1094. Car Pooling.h"


int main(int argc, const char * argv[]) {
    vector<vector<int>> input {{2,1,5},{3,3,7}};
    cout << P1049::Solution().carPooling(input, 4) << endl;
    return 0;
}
