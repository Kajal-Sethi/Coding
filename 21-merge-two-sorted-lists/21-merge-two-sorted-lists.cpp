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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1, *head2=list2, *n1, *n2, *final, *ret;
        
        final = new ListNode;
        final->val=0;
        final->next=NULL;
        
        if(head1==NULL)
            return head2;
        
        if(head2==NULL)
        {
            cout<<"kuch null ";
            return head1;
        }
        ret=final;

        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<=head2->val)
            {    
                n1 = head1->next;
                final->next = head1;
                head1 = n1;
                // cout<<"yaha ";
            }
            
            else
            {    
                n2 = head2->next;
                final->next = head2;
                head2 = n2;
                // cout<<"abbye ";
            }
            final=final->next;
        }
        
        if(head2!=NULL)
            final->next=head2;
        
        if(head1!=NULL)
            final->next=head1;
        
        return ret->next;
    }
    
    
    
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* head1=list1, *head2=list2, *n1, *n2, *final;
        
//         final = new ListNode;
        
//         if(head1==NULL)
//             return head2;
        
//         if(head2==NULL)
//             return head1;
        
//         if(list1->val > list2->val)
//             list1=list2;
        
// // list1;
//         // n1=head1;
//         // n2=head2;
//         while(head1!=NULL && head2!=NULL)
//         {
//             if(head1->val<=head2->val)
//             {    
// //                 while(head1!=NULL && head2!=NULL && head1->val<=head2->val)
// //                 {
// //                     n1=head1;
// //                     head1=head1->next;
// //                 }

// //                 n1->next=head2;
// //                 while(head1!=NULL && head2!=NULL && head2->val<head1->val)
// //                 {
// //                     n2=head2;
// //                     head2=head2->next;
// //                 }
// //                 n2->next=head1;
//                 final->next = head1;
//                 head1 = head1->next;
//             }
            
//             else
//             {    
// //                 while(head1!=NULL && head2!=NULL && head2->val<head1->val)
// //                 {
// //                     n2=head2;
// //                     head2=head2->next;
// //                 }
// //                 n2->next=head1;
                
// //                 while(head1!=NULL && head2!=NULL && head1->val<=head2->val)
// //                 {
// //                     n1=head1;
// //                     head1=head1->next;
// //                 }

// //                 n1->next=head2;
                
//                 final->next = head2;
//                 head2 = head2->next;
//             }
//         }
        
//         return list1;
//     }
};