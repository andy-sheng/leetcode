/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<TreeNode*> queue;
        int count = 1, nextCount = 2,n = 0;
        if (!root) {
            return result;
        }
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode *node = queue[0];
            tmp.push_back(node->val);
            if (node->left) {
                queue.push_back(node->left);
            } else {
                nextCount--;
            }
            if (node->right) {
                queue.push_back(node->right);
            } else {
                nextCount--;
            }
            queue.erase(queue.begin());
            n++;
            if (n == count) {
                result.insert(result.begin(), tmp);
                tmp.clear();
                
                count = nextCount;
                nextCount = count * 2;
                n=0;
            }
        }
        return result;
    }
};