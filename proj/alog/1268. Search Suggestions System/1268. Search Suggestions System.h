//
//  1268. Search Suggestions System.h
//  leetcode
//
//  Created by andysheng on 2020/1/1.
//  Copyright © 2020 Andy. All rights reserved.
//

#ifndef _268__Search_Suggestions_System_h
#define _268__Search_Suggestions_System_h
#include "DataStructures.h"
namespace P1268 {
    struct TrieTreeNode {
        int pass;
        int count;
        TrieTreeNode *node[26];
    };

    class Solution {
    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            TrieTreeNode *root = constructTrieTree(products);
            vector<vector<string>> ret;
            for (int i = 1; i <= searchWord.size(); ++i) {
                ret.push_back(match(root, searchWord.substr(0, i)));
            }
            return ret;
        }
        
        TrieTreeNode *constructTrieTree(vector<string>& words) {
            TrieTreeNode *root = new TrieTreeNode();
            for (string wordRoot : words) {
                TrieTreeNode * node = root;
                for (int i = 0; i < wordRoot.size(); ++i) {
                    int pos = wordRoot[i] - 'a';
                    if (!node->node[pos]) {
                        node->node[pos] = new TrieTreeNode();
                    }
                    node->pass++;
                    node = node->node[pos];
                }
                node->count++;
            }
            return root;
        }
        
        vector<string> match(TrieTreeNode *root, string keyWord) {
            if (!root) {
                return vector<string>();
            }
            for (char c : keyWord) {
                int pos = c - 'a';
                root = root->node[pos];
                if (!root) {
                    return vector<string>();
                }
            }
            vector<string> ret;
            int cnt = 3;
            travel(root, keyWord, cnt,ret);
            return ret;
        }
        
        void travel(TrieTreeNode *root, string word, int &n, vector<string> &ret) {
            if (root->count > 0) {
                ret.push_back(word);
                --n;
            }
            for (int i = 0; n > 0 && i < 26; ++i) {
                TrieTreeNode *node = root->node[i];
                if (node) {
                    word.push_back(i + 'a');
                    travel(node, word, n, ret);
                    word.pop_back();
                }
            }
        }
    };
}
#endif /* _268__Search_Suggestions_System_h */
