class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        result.push_back(root->val);
        
        vector<int> tmp;
        tmp = preorderTraversal(root->left);
        int n = tmp.size();
        for (int i = 0; i < n; i++) {
            result.push_back(tmp[i]);
        }
        vector<int> tmp2;
        tmp2 = preorderTraversal(root->right);
        n = tmp2.size();
        for (int i = 0; i < n; i++) {
            result.push_back(tmp2[i]);
        }
        
        return result;
        
    }
    
};