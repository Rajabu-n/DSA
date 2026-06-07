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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return NULL;
        if(head->next->next==nullptr)
        {
            head->next=nullptr;
            return head;
        }
        ListNode* slow=head;
        ListNode* prev=nullptr;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* delNode=slow;
        prev->next=slow->next;
        delete delNode;
        return head;
    }
};