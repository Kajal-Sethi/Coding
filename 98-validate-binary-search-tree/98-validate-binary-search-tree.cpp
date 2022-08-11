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
    
    bool minn, maxx;
    bool solve(TreeNode* root, int lt, int rg)
    {
        if(root==NULL)
            return true;
        
        if(root->val > lt && root->val < rg)
            return solve(root->left, lt, root->val) && solve(root->right, root->val, rg);
        
        if(root->val == lt && lt==INT_MIN && !minn && root->val < rg)
        {
            minn=true;
            return solve(root->left, lt, root->val) && solve(root->right, root->val, rg);            
        }
        
        if(root->val == rg && rg==INT_MAX && !maxx && root->val > lt)
        {
            maxx=true;
            return solve(root->left, lt, root->val) && solve(root->right, root->val, rg);            
        }
        
        return false;
    }
        
    bool isValidBST(TreeNode* root) {
        minn=false;
        maxx=false;
        return solve(root, INT_MIN, INT_MAX);
    }
};