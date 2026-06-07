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
    ListNode *findLastNode(ListNode* head,int pos)
    {
        int count=1;
        ListNode *cur=head;
        while(cur)
        {
            if(count==pos)return cur;
            cur=cur->next;
            count++;
        }
        return cur;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        if(head==nullptr|| head->next==nullptr)return head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        if(k%len==0)return head;
        k=k%len;
        ListNode *tail=head;
        while(tail->next)
        {
            tail=tail->next;
        }
        tail->next=head;
        int pos=len-k;
        ListNode *newLastNode=findLastNode(head,pos);
        head=newLastNode->next;
        newLastNode->next=nullptr;
       
        return head;
    }
};