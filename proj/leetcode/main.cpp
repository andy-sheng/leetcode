//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "890. Find and Replace Pattern.h"

int main(int argc, const char * argv[]) {
    
    vector<string> input {"abc","deq","mee","aqq","dkd","ccc"};
    
    for (string word: FindAndReplacePattern::Solution().findAndReplacePattern(input, "abb")) {
        cout << word << endl;
    }
    FindAndReplacePattern::Solution();
    
 
    return 0;
}
