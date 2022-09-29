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
    
    void see(TreeNode* root, map<TreeNode*, TreeNode*> &par)
    {
        if(root==NULL)
            return;
    
        if(root->left!=NULL)
            par[root->left] = root;
        
        
        if(root->right!=NULL)
            par[root->right] = root;
        
        see(root->left, par);
        see(root->right, par);
    }
        
    void point(TreeNode* root, int start, TreeNode* &st)
    {
        if(root==NULL || st!=NULL)
            return;
    
        if(root->val==start)
            st = root;

        point(root->left, start, st);
        point(root->right, start, st);
    }
        
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*, TreeNode*> par;
        set<TreeNode*> vis;
        
        par[root] = NULL;
        
        see(root, par);
        TreeNode* st = NULL;
        point(root, start, st);
        
        int count=-1, size;
        queue<TreeNode*> q;
        q.push(st);
        vis.insert(st);
        
        
        // cout<<"data "<<st->val<<" "<<start;
        while(!q.empty())
        {
            size=q.size();
            while(size>0)
            {
                st = q.front();
                q.pop();
                
                if(st)
                {
                    if(st->left && (vis.find(st->left)==vis.end()))
                    {
                        q.push(st->left);
                        vis.insert(st->left);
                    }

                    if(st->right && vis.find(st->right)==vis.end())
                    {
                        q.push(st->right);
                        vis.insert(st->right);
                    }

                    if(par[st] && vis.find(par[st])==vis.end())
                    {
                        q.push(par[st]);
                        vis.insert(par[st]);
                    }

                }
                
                size--;
            }
            
            count++;
        }
        
        return count;
    }
};