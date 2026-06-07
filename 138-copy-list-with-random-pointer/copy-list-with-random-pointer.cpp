/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mpp;
        if(!head)return nullptr;
        Node* temp=head;
        while(temp)
        {
            mpp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        Node *cur=head;
        while(cur)
        {
            mpp[cur]->next= mpp[cur->next];
            mpp[cur]->random=mpp[cur->random];
            cur=cur->next;
        }
        return mpp[head];
    }
};