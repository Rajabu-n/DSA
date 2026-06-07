/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDifference(ListNode *headA,ListNode *headB)
    {
        int len1=0;
        int len2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1)
        {
            len1++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2=temp2->next;
        }
        return len1-len2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int dif=getDifference(headA,headB);

        if(dif>0)
        {
            while(dif!=0)
            {
                headA=headA->next;
                dif--;
            }
        }
        else
        {
            while(dif!=0)
            {
                headB=headB->next;
                dif++;
            }
        }
        while(headA)
        {
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};