/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // if path is found then good else pop
    bool find_path(TreeNode* &root, TreeNode* &node, vector<TreeNode*> &path)
    {
        if(root==NULL)
            return false;
        
        if(root==node)
        {
            path.push_back(root);
            return true;
        }
        
        path.push_back(root);
        bool l=find_path(root->left, node, path);
        bool r=find_path(root->right, node, path);
        
        if(!l && !r)
        {
            path.pop_back();
            return false;
        }
        
        return true;
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        bool l=find_path(root, p, path1);
        bool r=find_path(root, q, path2);
        int i;
        
        for(i=0; i<min(path1.size(), path2.size()); i++)
            if(path1[i]!=path2[i])
                break;
        
        if(i-1<0)
            return NULL;
        
        return path1[i-1];        
    }
};