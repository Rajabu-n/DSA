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
    ListNode *reversell(ListNode *head)
    {
        ListNode* nextnode=head;
        ListNode* cur=head;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reversell(l1);
        l2=reversell(l2);

        ListNode* dummy=new ListNode(0);
        ListNode *temp=dummy;
        ListNode *newnode;
        int carry=0;
        while(l1 || l2|| carry)
        {
            int sum=carry;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                 sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            newnode =new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return reversell(dummy->next);
    }
};