//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "49. Group Anagrams.h"

int main(int argc, const char * argv[]) {
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    P49::Solution().groupAnagrams(input);
    return 0;
}
