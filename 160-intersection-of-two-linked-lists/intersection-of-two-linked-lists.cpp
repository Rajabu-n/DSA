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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode* cur1=headA; cur1!=nullptr;cur1=cur1->next)
        {
            for(ListNode* cur2=headB ;cur2!=nullptr;cur2=cur2->next)
            {
                if(cur1==cur2) return cur1;
            }
        }
        return nullptr;
    }
};