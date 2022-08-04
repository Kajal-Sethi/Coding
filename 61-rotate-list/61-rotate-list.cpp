/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // use 2 ptr from head and k distance
        ListNode* nd, *new_h, *prev;
        nd=head;
        new_h=head;
        int count=1;
        
        if(head==NULL)
            return head;
        
        while(new_h->next!=NULL)
        {
            count++;
            new_h=new_h->next;
        }
        
        k=k%count;
        // cout<<count;
        
        if(k==0)
            return head;            
            
        count=1;
        new_h=head; 
        nd==head; 
        prev=NULL;
        while(count<k && new_h->next!=NULL)
        {
            count++;
            // nd=new_h;
            new_h=new_h->next;
        }
        
        // cout<<nd->val<<endl;
        while(new_h->next!=NULL)
        {
            prev=nd;
            nd=nd->next;
            new_h=new_h->next;
        }
        
        prev->next=NULL;
        new_h->next=head;
        // cout<<nd->val;
        return nd;
    }
};