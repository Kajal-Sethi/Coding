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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode new_h = ListNode(0);
        ListNode new_2nd = ListNode(0);
        ListNode* before = &new_h, *after = &new_2nd, *temp;
        temp=head;
        
        while(temp!=NULL)
        {
            if(temp->val < x)
            {
                // cout<<temp->val;
                before->next = temp;
                before=before->next;
            }
            
            else
            {
                after->next = temp;
                after=after->next;
            }
            
            temp=temp->next;            
        }
        
        after->next = NULL;
        before->next = new_2nd.next;
        return new_h.next;
    }
};