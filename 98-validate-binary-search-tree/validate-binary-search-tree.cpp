class Solution {
public:

    bool solve(TreeNode* root, long minVal, long maxVal)
    {
        if(root == NULL)
            return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};