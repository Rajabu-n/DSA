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
        int len=0;
        ListNode* temp=head;
        if(head==nullptr|| head->next==nullptr)return head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(len==k) return head;
        while(k>0)
        {
            ListNode* cur=head;
            ListNode *prev=nullptr;
            while(cur->next)
            {
                prev=cur;
                cur=cur->next;
            }
            prev->next=nullptr;
            cur->next=head;
            head=cur;
            k--;
        }
        return head;
    }
};