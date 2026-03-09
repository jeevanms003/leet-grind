class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        queue<TreeNode*> q1, q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty()){
            
            TreeNode* n1 = q1.front();
            TreeNode* n2 = q2.front();
            
            q1.pop();
            q2.pop();
            
            // Both NULL
            if(n1 == NULL && n2 == NULL)
                continue;
            
            // One NULL
            if(n1 == NULL || n2 == NULL)
                return false;
            
            // Values mismatch
            if(n1->val != n2->val)
                return false;
            
            // Mirror insertion
            q1.push(n1->left);
            q2.push(n2->right);
            
            q1.push(n1->right);
            q2.push(n2->left);
        }
        
        return true;
    }
};