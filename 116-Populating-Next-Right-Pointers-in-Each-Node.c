/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *pnode = root, *node;
    if (root == NULL) {
        return;
    }
    root->next = NULL;
    if (root->left == NULL) {
        return;
    }
    node = root->left;
    while (pnode->left != NULL) {
        while (true) {
            pnode->left->next = pnode->right;
            if (pnode->next != NULL) {
                pnode->right->next = pnode->next->left;
                pnode = pnode->next;
            } else {
                pnode->right->next = NULL;
                pnode = node;
                node = pnode->left;
                break;
            }
        }
    }
}