int nodeHeight(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    
    int left = nodeHeight(root->left);
    if (left == -1) {
        return -1;
    }
    
    int right = nodeHeight(root->right);
    if (right == -1) {
        return -1;
    }
    
    if (left - right > 1 || left - right <  -1) {
        return -1;
    }
    
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (nodeHeight(root) == -1) {
        return false;
    }
    return true;
}