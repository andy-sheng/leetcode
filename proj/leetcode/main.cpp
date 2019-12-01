//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "609. Find Duplicate File in System.h"


int main(int argc, const char * argv[]) {
    vector<string> input {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    P609::Solution().findDuplicate(input);
    return 0;
}
