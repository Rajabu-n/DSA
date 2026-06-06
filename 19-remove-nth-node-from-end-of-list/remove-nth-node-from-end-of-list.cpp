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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1) return NULL;
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        int del=count-n;
        if(n==count)
        {
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }
        ListNode* cur=head;
        for(int i=1;i<del;i++)
        {
            cur=cur->next;
        }
        ListNode* delNode=cur->next;
        cur->next=cur->next->next;
        delete delNode;
        return head;
    }
};