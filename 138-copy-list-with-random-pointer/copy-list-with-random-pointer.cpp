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
        Node* temp=head;
        while(temp)
        {
            Node *copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            Node* copynode=temp->next;
            if(temp->random)
            {
                copynode->random=temp->random->next;
            }
            else copynode->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummynode=new Node(-1);
        while(temp)
        {
           
            Node *res=dummynode;
            while(temp)
            {
                res->next=temp->next;
                res=res->next;

                temp->next=temp->next->next;
                temp=temp->next;
            }
        }
        return dummynode->next;
    }
};