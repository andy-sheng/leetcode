//
//  LRU.h
//  leetcode
//
//  Created by andysheng on 2021/7/27.
//  Copyright © 2021 Andy. All rights reserved.
//

#ifndef LRU_h
#define LRU_h

#include "DataStructures.h"
#include <map>

namespace LRU {

typedef struct CacheNode {
    struct CacheNode *prev;
    struct CacheNode *next;
    int key;
    int value;
} CacheNode;

class Cache {
    map<int, CacheNode *> map;
    int capacity = 0;
    int count = 0;
    CacheNode *head = new CacheNode();
    CacheNode *tail = new CacheNode();
public:
    Cache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void set(int key, int value) {
        CacheNode *cacheNode = getCacheNode(key, true);
        cacheNode->value = value;

        if (count > capacity) {
            CacheNode *deleteNode = tail->prev;
            map.erase(deleteNode->key);
            deleteNode->prev->next = tail;
            tail->prev = deleteNode->prev;
            delete deleteNode;
            --count;
        }
    }
    int get(int key) {
        CacheNode *cacheNode = getCacheNode(key, false);
        if (cacheNode) {
            return cacheNode->value;
        }
        return -1;
    }
    
    CacheNode *getCacheNode(int key, int bCreate) {
        CacheNode *cacheNode = NULL;
        if (map.find(key) == map.end()) {
            if (bCreate) {
                cacheNode =  new CacheNode();
                cacheNode->key = key;
                ++count;
                map[key] = cacheNode;
            }
        } else {
            cacheNode = map[key];
            // delete cacheNode
            cacheNode->prev->next = cacheNode->next;
            cacheNode->next->prev = cacheNode->prev;
        }
        if (cacheNode) {
            // attach to head
            cacheNode->next = head->next;
            head->next->prev= cacheNode;
            head->next = cacheNode;
            cacheNode->prev = head;
        }
        
        return cacheNode;
    }
};

}
#endif /* LRU_h */
