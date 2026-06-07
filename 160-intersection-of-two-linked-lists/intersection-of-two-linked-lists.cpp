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
        unordered_set<ListNode*>freq;
        ListNode* temp=headA;
        while(temp)
        {
            freq.insert(temp);
            temp=temp->next;
        }
        
        ListNode* i=headB;
        while(i)
        {
            if(freq.find(i)!=freq.end())return i;
            i=i->next;
        }
        return nullptr;
    }
};