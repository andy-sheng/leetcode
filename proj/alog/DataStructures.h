//
//  DataStructures.h
//  leetcode
//
//  Created by andysheng on 2019/9/30.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef DataStructures_h
#define DataStructures_h

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

namespace Algorithm {

bool compare1(int a, int b) {
    return b > a;
}


void bubbleSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - i; ++j) {
            if (!compare1(arr[j], arr[j+1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = i; j > 0 && !compare1(arr[j-1], arr[j]); --j) {
            swap(arr[j], arr[j-1]);
        }
    }
}

void mergeSort(vector<int> &arr, int begin, int end) {
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    
    vector<int> tmp(end - begin + 1);
    int i = begin;
    int j = mid + 1;
    int n = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            tmp[n++] = arr[i++];
        } else {
            tmp[n++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[n++] = arr[i++];
    }
    while (j <= end) {
        tmp[n++] = arr[j++];
    }
    for (int i = begin; i <= end; ++i) {
        arr[i] = tmp[i-begin];
    }
}

void quickSort(vector<int> &arr, int begin, int end) {
    if (begin > end) return;
    int pivot = begin;
    int head  = begin + 1;
    int tail  = end;
    while (tail >= head) {
        while (tail >= head) {
            if (arr[tail] < arr[pivot]) {
                swap(arr[tail], arr[pivot]);
                pivot = tail;
                --tail;
                break;
            }
            --tail;
        }
        while (tail >= head) {
            if (arr[head] > arr[pivot]) {
                swap(arr[head], arr[pivot]);
                pivot = head;
                ++head;
                break;
            }
            ++head;
        }
    }
    quickSort(arr, begin, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

void adjustHeap(vector<int> &arr, int begin, int end) {
    int tmp = arr[begin];
    int targetPos = begin;
    for (int i = begin * 2 + 1; i <= end; i = i * 2 + 1) {
        if (i + 1 <= end && arr[i + 1] > arr[i]) ++i;
        if (arr[i] > tmp) {
            arr[targetPos] = arr[i];
            targetPos = i;
        } else {
            break;
        }
    }
    arr[targetPos] = tmp;
}

void makeHeap(vector<int> &arr, int begin, int end) {
    for (int i = end / 2 + 1; i >= begin; --i) {
        adjustHeap(arr, i, end);
    }
}

void heapSort(vector<int> &arr, int begin, int end) {
    makeHeap(arr, begin, end);
    for (int i = end; i >= begin; --i) {
        swap(arr[i], arr[begin]);
        adjustHeap(arr, begin, i - 1);
    }
}

int binarySearch(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void kmp() {
    
}

void unionFind() {
    
}

}

#endif /* DataStructures_h */
