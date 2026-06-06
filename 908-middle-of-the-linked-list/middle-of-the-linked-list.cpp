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
    ListNode* middleNode(ListNode* head) {
        int length=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            length++;
            temp=temp->next;
        }
        if(length==1)return head;
        int pos=length/2;
        ListNode* cur=head;
        int k=0;
        while(cur!=nullptr)
        {
            k++;
            cur=cur->next;
            if(k==pos)return cur;
        }
        return cur;
    }
};