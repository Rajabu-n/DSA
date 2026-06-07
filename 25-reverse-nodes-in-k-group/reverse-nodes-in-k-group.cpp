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
    ListNode* reverselinkedlist(ListNode* head)
    {
        ListNode* cur=head;
        ListNode* nextnode=head;
        ListNode* prev=nullptr;
        while(nextnode)
        {
            nextnode=nextnode->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* head,int k)
    {
        ListNode* temp=head;
        k=k-1;
        while(k>0 && temp)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=nullptr;
        while(temp)
        {
            ListNode* kthNode=getKthNode(temp,k);
            if(kthNode==nullptr)
            {
                if(prevLast)prevLast->next=temp;
                break;
            }
            ListNode* nextGrpStart=kthNode->next;
            kthNode->next=nullptr;
            ListNode *newHead=reverselinkedlist(temp);
            if(temp==head)
            {
                head=newHead;
            }
            else
            {
                prevLast->next=newHead;
            }
            prevLast=temp;
            temp=nextGrpStart;

        }
        return head;
    }
};