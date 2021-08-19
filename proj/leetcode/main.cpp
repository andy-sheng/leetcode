//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "90. Subsets II.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input = {1,1};
    for (auto subset: P90::Solution().subsetsWithDup(input)) {
        cout << "sub set: ";
        for (auto item: subset) {
            cout << item << " ";
        }
        cout << endl;
    }
    
    return 0;
}
