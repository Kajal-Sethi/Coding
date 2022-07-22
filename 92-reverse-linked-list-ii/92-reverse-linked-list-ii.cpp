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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL || left==right)
            return head;
        
        ListNode *a, *b, *c, *d;
        a=NULL;
        b=head;
        int count=0;
        
        while(count < left-1)
        {
            count++;
            a=b;
            b=b->next;
        }
        
        // if(b->val!=left)
        //     return head;
        
        c=NULL;
        d=head;
        count=0;
        
        while(count < right-1)
        {
            count++;
            d=d->next;
        }
        
        cout<<b->val<<" "<<d->val;

        c=d->next;
        // reverse btw b and d
        
        ListNode *prev, *agla, *curr;
        prev=b;
        curr = b->next;
        agla = curr->next;
        
        while(prev!=d)
        {
            curr->next = prev;
            prev = curr;
            curr = agla;
            if(agla!=NULL && agla->next!=NULL)
                agla=agla->next;
        }
        
        b->next=c;
        
        if(a!=NULL)
        {
            a->next = d;
            return head;
        }
        
        return d;
    }
};