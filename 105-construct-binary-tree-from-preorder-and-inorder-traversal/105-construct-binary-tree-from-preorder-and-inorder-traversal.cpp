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
    
    // stores the index of the preoder we are currently at
    int curr;
        
    // start and end are for inorder. it tells us the size of array to be considered in inorder
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode* root = new (TreeNode);
        root->val = preorder[curr];
        root->left = NULL;
        root->right = NULL;
        
        curr+=1;
        if(start==end)
            return root;
        
        // find the breaking pt in inorder
        int i;
        for(i=0; i<inorder.size(); i++)
            if(inorder[i]==preorder[curr-1])
                break;
        
        root->left = solve(preorder, inorder, start, i-1);
        root->right = solve(preorder, inorder, i+1, end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre: PLR
        // in: LPR
        curr=0;
        return solve(preorder, inorder, 0, preorder.size()-1);
    }
};