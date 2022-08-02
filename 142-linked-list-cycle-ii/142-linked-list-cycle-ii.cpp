/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int count=0;

        if(head==NULL ||head->next==NULL)
            return NULL;
        
        ListNode *slow = head, *fast = head->next;
        while(slow!=fast && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        
        if(fast->next==NULL || fast->next->next==NULL)
            return NULL;
        
        do
        {
            slow=slow->next;
            fast = fast->next->next;
            count++;
        }while(slow!=fast);
        
        slow=head;
        fast=head;
        while(count>0)
        {
            fast=fast->next;
            count--;
        }
        
        // cout<<slow->val<<" "<<fast->val;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast;
    }
};