class Solution {
public:
    
    bool dfs(TreeNode* root, int currentSum, int targetSum) {
        
        if(root == NULL)
            return false;
        
        // Add current node value
        currentSum += root->val;
        
        // If leaf node, check sum
        if(root->left == NULL && root->right == NULL) {
            return currentSum == targetSum;
        }
        
        // Continue searching left or right
        return dfs(root->left, currentSum, targetSum) ||
               dfs(root->right, currentSum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};