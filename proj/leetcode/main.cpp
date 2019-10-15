//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "763. Partition Labels.h"

int main(int argc, const char * argv[]) {
    
    
    for (int i : PartitionLabels::Solution().partitionLabels("caedbdedda")) {
        cout << i <<endl;
    }
 
    return 0;
}
