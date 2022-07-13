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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // use q
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            while(size>0)
            {
                TreeNode* use = q.front();
                q.pop();
                size--;
                if(use->left!=NULL)
                    q.push(use->left);
                
                if(use->right!=NULL)
                    q.push(use->right);
                
                temp.push_back(use->val);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};