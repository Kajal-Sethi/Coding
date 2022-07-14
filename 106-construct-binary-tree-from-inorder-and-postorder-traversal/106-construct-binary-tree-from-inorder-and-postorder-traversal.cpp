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
    
    int curr;
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode* root = new TreeNode;
        root->val = postorder[curr];
        root->left = NULL;
        root->right = NULL;
        
        // since curr has been use decrement it
        
        curr--;
        if(start==end)
            return root;
        
        int i;
        for(i=0; i<postorder.size(); i++)
            if(inorder[i]==postorder[curr+1])
                break;
        
        root->right = solve(inorder, postorder, i+1, end);
        root->left = solve(inorder, postorder, start, i-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // post: LRP
        // in: LPR
        curr=inorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1);
    }
};