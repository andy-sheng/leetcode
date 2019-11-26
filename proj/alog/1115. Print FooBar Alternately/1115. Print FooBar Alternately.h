//
//  1115. Print FooBar Alternately.h
//  leetcode
//
//  Created by andysheng on 2019/11/27.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _115__Print_FooBar_Alternately_h
#define _115__Print_FooBar_Alternately_h
#include "DataStructures.h"
namespace P1115 {
    class FooBar {
    private:
        int n;
        std::mutex fooLock;
        std::mutex barLock;
    public:
        FooBar(int n) {
            this->n = n;
            fooLock.unlock();
            barLock.lock();
        }

        void foo(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                
                // printFoo() outputs "foo". Do not change or remove this line.
                fooLock.lock();
                printFoo();
                barLock.unlock();
            }
        }

        void bar(function<void()> printBar) {
            
            for (int i = 0; i < n; i++) {
                
                // printBar() outputs "bar". Do not change or remove this line.
                barLock.lock();
                printBar();
                fooLock.unlock();
                
            }
        }
    };
}
#endif /* _115__Print_FooBar_Alternately_h */
