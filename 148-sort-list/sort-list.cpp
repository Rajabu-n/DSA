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
    ListNode* mergeLinkedList(ListNode* list1,ListNode* list2)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
            if(list1)  temp->next=list1;  
            if(list2)  temp->next=list2;
               
        return dummy->next;
        
    }
    ListNode* findMiddleNode(ListNode *head)
    {
        if(head==nullptr|| head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* middle=findMiddleNode(head);
       
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=nullptr;
        

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        return mergeLinkedList(lefthead,righthead);
    }
};