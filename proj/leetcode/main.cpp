//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "540. Single Element in a Sorted Array.h"


int main(int argc, const char * argv[]) {
    vector<int> input {1,1,2,2,3};
//    vector<int> input {3,3,7,7,10,11,11};
    cout << P540::Solution().singleNonDuplicate(input)<<endl;
    return 0;
}
