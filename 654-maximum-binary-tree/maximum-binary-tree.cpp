/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    TreeNode* dfs(vector<int>& nums, int l, int r){

        if(l > r)
            return NULL;

        // Find max element index
        int maxIndex = l;
        for(int i=l;i<=r;i++){
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = dfs(nums, l, maxIndex-1);
        root->right = dfs(nums, maxIndex+1, r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};