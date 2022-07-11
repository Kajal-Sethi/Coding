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
    vector<int> rightSideView(TreeNode* root) {
        // level order traversal from right side
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        TreeNode* nd = root;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            
            nd = q.front();
            q.pop();
            ans.push_back(nd->val);

            if(nd->right!=NULL)
                q.push(nd->right);

            if(nd->left!=NULL)
                q.push(nd->left);
                
            n--;
            
            while(n>0)
            {
                nd = q.front();
                q.pop();
                
                if(nd->right!=NULL)
                    q.push(nd->right);
                
                if(nd->left!=NULL)
                    q.push(nd->left);
                
                n--;
            }
        }
        
        return ans;
    }
};