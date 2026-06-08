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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode *prev=dummyNode;

        if(head==nullptr || head->next==nullptr) return head;
        while(prev->next && prev->next->next)
        {
            ListNode* firstnode=prev->next;
            ListNode* secondnode=prev->next->next;

            firstnode->next=secondnode->next;
            secondnode->next=firstnode;
            prev->next=secondnode;

            prev=firstnode;
        }
        return dummyNode->next;
    }
};