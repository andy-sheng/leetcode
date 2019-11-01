//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1043. Partition Array for Maximum Sum.h"

int main(int argc, const char * argv[]) {
    
    vector<int> input {1,15,7,9,2,5,10};
    cout << PartitionArrayForMaximumSum::Solution().maxSumAfterPartitioning(input, 3) << endl;
    
    return 0;
}
