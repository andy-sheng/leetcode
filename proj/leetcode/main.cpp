//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "47. Permutations II.h"

int main(int argc, const char * argv[]) {
    vector<int> input {1,1,3};
    for (auto i: P47::Solution().permuteUnique(input)) {
        for (auto j: i) {
            cout << j <<" ";
        }
        cout << endl;
    }
    return 0;
}
