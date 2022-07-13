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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // use 2 stack. one from left to right and second from right to left
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
            
        TreeNode* curr;
        stack<TreeNode*> st1, st2;
        
        st1.push(root);
        
        int turn =1, size;
        while(!st1.empty() || !st2.empty())
        {
            vector<int> vec;
            if(turn == 1)
            {
                while(!st1.empty())
                {
                    curr = st1.top();
                    st1.pop();

                    if(curr->left!=NULL)
                        st2.push(curr->left);

                    if(curr->right!=NULL)
                        st2.push(curr->right);
                    
                    vec.push_back(curr->val);
                }
                
                turn = 2;
            }
                
            else
            {
                while(!st2.empty())
                {
                    curr = st2.top();
                    st2.pop();
                    
                    if(curr->right!=NULL)
                        st1.push(curr->right);

                    if(curr->left!=NULL)
                        st1.push(curr->left);

                    vec.push_back(curr->val);
                }               
                
                turn = 1;
            }
            
            ans.push_back(vec);
        }
        
        return ans;
    }
};