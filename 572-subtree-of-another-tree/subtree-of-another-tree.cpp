class Solution {
public:
    
    // Check if two trees are identical
    bool isSameTree(TreeNode* a, TreeNode* b) {
        
        if(a == NULL && b == NULL)
            return true;
        
        if(a == NULL || b == NULL)
            return false;
        
        if(a->val != b->val)
            return false;
        
        return isSameTree(a->left, b->left) &&
               isSameTree(a->right, b->right);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL)
            return false;
        
        // If current tree matches
        if(isSameTree(root, subRoot))
            return true;
        
        // Otherwise check left or right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};