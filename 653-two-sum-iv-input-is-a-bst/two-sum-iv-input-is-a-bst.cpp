class Solution {
public:

    bool dfs(TreeNode* root, int k, unordered_set<int>& s)
    {
        if(root == NULL)
            return false;

        if(s.count(k - root->val))
            return true;

        s.insert(root->val);

        return dfs(root->left, k, s) || dfs(root->right, k, s);
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> s;

        return dfs(root, k, s);
    }
};