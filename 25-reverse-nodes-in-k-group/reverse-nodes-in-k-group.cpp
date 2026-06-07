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
    ListNode* reverseKGroup(ListNode* head, int k) {
     if(k<=1 ||head==nullptr) return head;
     ListNode *dummy=new ListNode(0);
     dummy->next=head;
     ListNode *prevgroupend=dummy;
     while(true)
     {
         ListNode *kth=prevgroupend;
         for(int i=0;i<k;i++)
         {
            kth=kth->next;
            if(kth==nullptr) return dummy->next;
         }
          ListNode *groupstart=prevgroupend->next;
          ListNode *nextgroupstart=kth->next;

           ListNode *prev=nextgroupstart;
            ListNode *cur=groupstart;

            while(cur!=nextgroupstart)
            {
                 ListNode *temp=cur->next;
                 cur->next=prev;
                 prev=cur;
                 cur=temp;
            }
            prevgroupend->next=prev;
            prevgroupend=groupstart;
     }
     return dummy->next;
    }
 };