//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include "1115. Print FooBar Alternately.h"

void printFoo()
{
    cout << "foo" <<endl;
}
int main(int argc, const char * argv[]) {
    
    P1115::FooBar(2).foo(printFoo);
    return 0;
}
