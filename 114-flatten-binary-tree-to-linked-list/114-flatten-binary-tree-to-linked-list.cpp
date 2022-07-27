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
    
    void flatten(TreeNode* root) {
        TreeNode* temp, *rig;
        
        while(root)
        {
            // ek left chahiye
            if(root->left)
            {
                rig = root->right;
                temp = root->left;

                while(temp->right)
                    temp=temp->right;

                temp->right = rig;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }
};