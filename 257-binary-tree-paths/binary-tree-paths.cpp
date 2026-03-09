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
    
    void solve(TreeNode* root, string path, vector<string>& ans) {
        
        if(root == NULL) return;
        
        // Add current node value to path
        if(path == "")
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);
        
        // If leaf node, push to answer
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        
        // Recurse left and right
        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};