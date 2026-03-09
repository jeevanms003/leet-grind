class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);
        
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
            
            // Values different
            if(n1->val != n2->val)
                return false;
            
            q1.push(n1->left);
            q2.push(n2->left);
            
            q1.push(n1->right);
            q2.push(n2->right);
        }
        
        return true;
    }
};