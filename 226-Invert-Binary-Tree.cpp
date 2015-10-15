class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* newRoot = (TreeNode*)malloc(sizeof(TreeNode));
        newRoot->val = root->val;
        newRoot->right = invertTree(root->left);
        newRoot->left = invertTree(root->right);
        return newRoot;
    }
    
};