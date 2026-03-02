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

    int findMaxIndex(vector<int>& nums, int l, int r){
        int index = l;
        for(int i=l;i<=r;i++){
            if(nums[i] > nums[index])
                index = i;
        }
        return index;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        if(nums.empty())
            return NULL;

        // Root = maximum of entire array
        int rootIndex = findMaxIndex(nums,0,nums.size()-1);
        TreeNode* root = new TreeNode(nums[rootIndex]);

        // Queue stores node and subarray range
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,nums.size()-1}});

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int left = curr.second.first;
            int right = curr.second.second;

            int maxIndex = findMaxIndex(nums,left,right);

            // Left subtree
            if(left <= maxIndex-1){
                int leftMax = findMaxIndex(nums,left,maxIndex-1);
                node->left = new TreeNode(nums[leftMax]);

                q.push({node->left,{left,maxIndex-1}});
            }

            // Right subtree
            if(maxIndex+1 <= right){
                int rightMax = findMaxIndex(nums,maxIndex+1,right);
                node->right = new TreeNode(nums[rightMax]);

                q.push({node->right,{maxIndex+1,right}});
            }
        }

        return root;
    }
};