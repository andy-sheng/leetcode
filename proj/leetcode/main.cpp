//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "78. Subsets.h"


int main(int argc, const char * argv[]) {
    vector<int> input{1,2,3};
  
    for (auto tmp: P78::Solution().subsets(input)) {
        for (auto i: tmp) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
