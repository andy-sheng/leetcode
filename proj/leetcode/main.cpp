//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "77. Combinations.h"

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> combinations = P77::Solution().combine(1,1);
    for (auto combination: combinations) {
        for (auto item: combination) {
            cout << item <<" ";
        }
        cout << endl;
    }
    
    return 0;
}
