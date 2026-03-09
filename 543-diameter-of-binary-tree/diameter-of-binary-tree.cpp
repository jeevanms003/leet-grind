class Solution {
public:
    
    int diameter = 0;
    
    int dfs(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        // Update diameter
        diameter = max(diameter, left + right);
        
        // Return height
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);
        
        return diameter;
    }
};