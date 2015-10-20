/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* toBST(int *nums, int start, int end) {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[(start + end) / 2];
    
    if (start == end) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    root->left = (end - start == 1) ? NULL : toBST(nums, start, (start + end) / 2 - 1);
    root->right = toBST(nums, (start + end) / 2 + 1, end);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }
    struct TreeNode* root = toBST(nums, 0, numsSize - 1);
    return root;
}