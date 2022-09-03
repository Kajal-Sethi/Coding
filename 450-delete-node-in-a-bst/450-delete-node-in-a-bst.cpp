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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        
        else        // we are on the key
        {
            if(root->left==NULL && root->right==NULL)
                return NULL;
            
            else if(root->left==NULL)
                return root->right;
            
            else if(root->right==NULL)
                return root->left;
                
            else        // find inorder successor
            {
                TreeNode* temp, *prev;
                prev = temp = root->right;
                // succ
                while(temp->left!=NULL)
                {
                    prev = temp;
                    temp=temp->left;
                }
                
                if(prev!=temp)
                {    
                    prev->left = temp->right;
                    root->val = temp->val;
                    delete(temp);
                }
                
                else
                {    
                    root->right = temp->right;
                    root->val = temp->val;
                    delete(temp);
                }   
                return root;
            }
        }
        
    }
};