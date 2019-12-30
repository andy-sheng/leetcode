//
//  648. Replace Words.h
//  leetcode
//
//  Created by andysheng on 2019/12/31.
//  Copyright © 2019 Andy. All rights reserved.
//

#ifndef _48__Replace_Words_h
#define _48__Replace_Words_h

#include "DataStructures.h"

namespace P648 {
    struct TrieTreeNode {
        int pass;
        int count;
        TrieTreeNode *node[26];
    };

    class Solution {
    public:
        string replaceWords(vector<string>& dict, string sentence) {
            TrieTreeNode *root = constructTrieTree(dict);
            int loc = 0;
            string ret = "";
            for (int i = 0; i < sentence.size(); ++i) {
                if (sentence[i] == ' ') {
                    string wordRoot = findRoot(root, sentence.substr(loc, i - loc));
                    ret = ret + ((ret.size() == 0) ? "" : " ") + wordRoot;
                    loc = i + 1;
                } else if (i == sentence.size() - 1) {
                    string wordRoot = findRoot(root, sentence.substr(loc, i - loc + 1));
                    ret = ret + ((ret.size() == 0) ? "" : " ") + wordRoot;
                    loc = i + 1;
                }
            }
            return ret;
        }
        
        TrieTreeNode *constructTrieTree(vector<string>& dict) {
            TrieTreeNode *root = new TrieTreeNode();
            for (string wordRoot : dict) {
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
        string findRoot(TrieTreeNode *root, string word) {
            for (int i = 0; i < word.size(); ++i) {
                int pos = word[i] - 'a';
                if (!root->node[pos]) {
                    return word;
                }
                root = root->node[pos];
                if (root->count > 0) {
                    return word.substr(0, i + 1);
                }
            }
            return word;
        }
    };
}
#endif /* _48__Replace_Words_h */
