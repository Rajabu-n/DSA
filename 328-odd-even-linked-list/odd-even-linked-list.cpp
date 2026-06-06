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
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr || head->next==nullptr||head->next->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next; 

        ListNode* oddhead=slow;
        ListNode* evenhead=fast;

        ListNode* oddorghead=slow;
        ListNode* evenorghead=fast;
        

        while(fast&& slow&& slow->next && fast->next)
        {
                slow=slow->next->next;
                fast=fast->next->next;
                oddhead->next=slow;
                evenhead->next=fast;
                oddhead=oddhead->next;
                evenhead=evenhead->next;
        }
        oddhead->next=evenorghead;
        return oddorghead;
    }
};