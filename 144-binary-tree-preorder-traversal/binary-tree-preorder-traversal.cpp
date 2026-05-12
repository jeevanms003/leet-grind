/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode* root,vector<int> &arr)
    {
        if(root == nullptr)
        {return;}
        arr.push_back(root->val);
        trav(root->left,arr);
        trav(root->right,arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        trav(root,arr);
        return arr;
        
    }
};