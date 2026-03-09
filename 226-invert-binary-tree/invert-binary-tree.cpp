class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        // Swap left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};