class Solution {
public:

    int dfs(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left);
        if(left == -1)
            return -1;
            
        int right = dfs(root->right);
        if(right == -1)
            return -1;
            
        if(abs(left - right) > 1)
            return -1;
            
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};