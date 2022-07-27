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
    vector<TreeNode*> use;
    
    void preorder(TreeNode *root)
    {
        if(root==NULL)
            return;
            
        use.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        int i;
        
        if(root==NULL)
            return;
        
        preorder(root);
        for(i=0; i<use.size()-1; i++)
        {
            use[i]->left=NULL;
            use[i]->right=use[i+1];
        }
    }
};