//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1238. Circular Permutation in Binary Representation.h"

int main(int argc, const char * argv[]) {
    for (auto i : CircularPermutationInBinaryRepresentation::Solution().circularPermutation(3, 2)) {
        cout <<  std::bitset<32>(i) << endl;
    }
    return 0;
}
