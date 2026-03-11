class Solution {
public:

    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    unordered_map<int,int>& mp)
    {
        if(ps > pe || is > ie) return NULL;

        int rootVal = preorder[ps];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = mp[rootVal];
        int numsLeft = inRoot - is;

        root->left = build(preorder, ps+1, ps+numsLeft,
                           inorder, is, inRoot-1, mp);

        root->right = build(preorder, ps+numsLeft+1, pe,
                            inorder, inRoot+1, ie, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return build(preorder,0,preorder.size()-1,
                     inorder,0,inorder.size()-1, mp);
    }
};