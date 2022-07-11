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
    
    void solve(TreeNode* root, string &q)
    {
        if(root==NULL)
            return;
        
        string ab = to_string(root->val);
        q = q+ab;
        if(root->left!=NULL)
        {
            q.push_back('(');
            solve(root->left, q);
            q.push_back(')');
        }
        
        if(root->left==NULL && root->right!=NULL)
        {
            q.push_back('(');
            q.push_back(')');
        }
        
        if(root->right!=NULL)
        {
            q.push_back('(');
            solve(root->right, q);
            q.push_back(')');
        }
    }
        
    string tree2str(TreeNode* root) {
        string q = "";        
        solve(root, q);
        return q;
    }
};