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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        if(head->next->next==nullptr)
        {
            if(head->val==head->next->val)return true;
            else return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;//for odd length slow should not get reversed

        ListNode* nextnode=slow;
         ListNode*cur=slow;
        ListNode* prev=nullptr;
        while(nextnode!=nullptr)
        {
            nextnode=nextnode->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
        }
         ListNode*temp=head;
        ListNode* reversedhead=prev;
        while(temp!=nullptr && reversedhead!=nullptr)
        {
            if(temp->val!=reversedhead->val)return false;
            temp=temp->next;
            reversedhead=reversedhead->next;
        }
        return true;
    }
};