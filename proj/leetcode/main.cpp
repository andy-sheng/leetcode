//
//  main.cpp
//  leetcode
//
//  Created by andysheng on 2019/8/10.
//  Copyright © 2019 Andy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "99. Recover Binary Search Tree.h"



int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    P99::Solution().findNode(root);
    
    
//    srand((unsigned)time(NULL));
//    Algorithm::UnionFind unionFind(10);
//    unionFind.Union(1, 2);
//    unionFind.Union(2, 3);
//    unionFind.Union(4, 5);
//    unionFind.Union(5, 6);
//
//    cout << unionFind.isConnected(1, 2) << endl;
    
    
//    srand((unsigned)time(NULL));
//    for (int i = 0; i < 10; ++i) {
//        vector<int> input1 ;
//        vector<int> input2 ;
//        for (int i = 0; i < 100; ++i) {
//            int tmp = rand() % 10000;
//            input1.push_back(tmp);
//            input2.push_back(tmp);
//        }
//
//    //    Algorithm::bubbleSort(input1);
//    //    Algorithm::selectSort(input1);
//    //    Algorithm::quickSort(input1, 0, input1.size() - 1);
//    //    Algorithm::mergeSort(input1, 0, input1.size() - 1);
//        Algorithm::heapSort(input1, 0, input1.size() - 1);
//        sort(input2.begin(), input2.end());
//
//        bool ret = true;
//        for (int i = 0; i < input1.size(); ++i) {
////            cout << input1[i] << " --- " << input2[i] << endl;
//            if (input1[i] != input2[i]) {
//                ret = false;
//                break;
//            }
//        }
//        cout << ret << endl;
//    }
    
    
    
    
    
//    vector<int> arr {1,2,3,5,6};
//    cout << Algorithm::binarySearch(arr, 0) << endl;
    
    
    return 0;
}
