class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<int> fromLeft;
        vector<int> fromRight;
        if (root == NULL) {
            return result;
        }
        fromLeft = inorderTraversal(root->left);
        int n = fromLeft.size();
        for (int i = 0; i < n; i++) {
            result.push_back(fromLeft[i]);
        }
        result.push_back(root->val);
        fromRight = inorderTraversal(root->right);
        n = fromRight.size();
        for (int i = 0; i < n; i++) {
            result.push_back(fromRight[i]);
        }
        return result;
    }
};