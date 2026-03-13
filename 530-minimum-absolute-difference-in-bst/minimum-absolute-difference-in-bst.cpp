class Solution {
public:

    void dfs(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL)
            return;

        arr.push_back(root->val);

        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    int getMinimumDifference(TreeNode* root) {

        vector<int> arr;

        dfs(root, arr);

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for(int i = 1; i < arr.size(); i++)
        {
            ans = min(ans, arr[i] - arr[i-1]);
        }

        return ans;
    }
};