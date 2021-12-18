//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "106. Construct Binary Tree from Inorder and Postorder Traversal.h"

int main(int argc, const char * argv[]) {
  
    vector<int> input1 {1,3,2};
    vector<int> input2 {3,2,1};
    cout << P106::Solution().buildTree(input1, input2) << endl;
    return 0;
}
