/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool travel(struct TreeNode* leftNode, struct TreeNode* rightNode) {
    if (leftNode == rightNode) {
        return true;
    }
    if (!leftNode || !rightNode) {
        return false;
    }
    if (leftNode->val != rightNode->val) {
        return false;
    }
    return travel(leftNode->left, rightNode->right) && travel(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    return travel(root->left, root->right);
    
}