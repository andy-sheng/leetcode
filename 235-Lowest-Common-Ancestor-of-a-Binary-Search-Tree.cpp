class Solution {
public:
    vector<TreeNode*> pathP, pathQ;
    void travel(TreeNode* root, TreeNode* &p, TreeNode* &q, int level) {
        if (root == NULL) {
            return;
        }
        if (p != NULL) {
            if (level + 1 > pathP.size()) {
                pathP.push_back(root);
            } else {
                pathP[level] = root;
            }
            if (root == p) {
                p = NULL;
            }
        }
        if (q != NULL) {
            if (level + 1 > pathQ.size()) {
                pathQ.push_back(root);
            } else {
                pathQ[level] = root;
            }
            if (root == q) {
                q = NULL;
            }
        }
        travel(root->left, p, q, level + 1);
        travel(root->right, p, q, level + 1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root, p, q, 0);
        int n = (pathP.size() > pathQ.size()) ? pathP.size() : pathQ.size();
        for (int  i = 0; i < n; i++) {
            if (pathP[i] != pathQ[i]) {
                return pathP[i - 1];
            }
        }
        return NULL;
    }
    
};