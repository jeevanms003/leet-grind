class Solution {
public:

    bool dfs(TreeNode* root, int k, unordered_map<int,int>& mp)
    {
        if(root == NULL)
            return false;

        int complement = k - root->val;

        if(mp.count(complement))
            return true;

        mp[root->val]++;

        return dfs(root->left, k, mp) || dfs(root->right, k, mp);
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_map<int,int> mp;

        return dfs(root, k, mp);
    }
};