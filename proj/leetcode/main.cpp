//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "347. Top K Frequent Elements.h"


int main(int argc, const char * argv[]) {
    vector<int> input{-1,1,3,3,3,4,5,5,5,5,6,6,7,8};
    
    for (int i: P347::Solution().topKFrequent(input, 3)) {
        cout << i << endl;
    }
    return 0;
}
