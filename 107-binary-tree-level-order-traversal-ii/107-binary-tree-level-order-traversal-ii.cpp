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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> ans, ret;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            temp.clear();
            int siz = q.size();
            while(siz>0)
            {
                TreeNode* use = q.front();
                q.pop();
                if(use->left!=NULL)
                    q.push(use->left);
                
                if(use->right!=NULL)
                    q.push(use->right);
                
                temp.push_back(use->val);
                siz--;
            }
            ans.push_back(temp);
        }
        
        int start=0, end=ans.size()-1;
        
        while(start<end)
        {
            // temp = ans[start];
            swap(ans[start], ans[end]);
            start++;
            end--;
        }
        
        return ans;
    }
};