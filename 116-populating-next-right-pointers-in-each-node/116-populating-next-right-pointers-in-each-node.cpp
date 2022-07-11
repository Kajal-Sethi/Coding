/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        
        queue<Node*> q, use;
        Node* nd, *temp;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            
            while(n>0)
            {
                nd = q.front();
                q.pop();
                n = n-1;
                
                if(n>0)
                {
                    temp = q.front();
                    nd->next = temp;
                }
                
                else
                    nd->next = NULL;
                
                if(nd->left!=NULL)
                    q.push(nd->left);
                
                if(nd->right!=NULL)
                    q.push(nd->right);
                                
            }
            
            // Node* temp=(Node*)malloc(sizeof(Node));
            // temp->val = 1001;
            // temp->left=NULL;
            // temp->right=NULL;
            // use.push(temp);
        }
        
//         cout<<use.size();
//         while(!use.empty())
//         {
//              Node* temp;
//             temp = use.front();
//             use.pop();
            
//             nd = use.front();
            
//             if(nd->val==1001)
//             {
//                 use.pop();
//                 temp->right = NULL;
//             }
            
//             else
//                 temp->right = nd;
                
//         }
        
        return root;
    }
};