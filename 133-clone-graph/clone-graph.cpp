/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        Node *clone=new Node(node->val);
        mp[node]=clone;

        q.push(node);

        while(!q.empty())
        {
            Node *cur=q.front();
            q.pop();

            for(Node *neigh:cur->neighbors)
            {
                //if does not exist in the map create the node
                if(mp.find(neigh)==mp.end())
                {
                    mp[neigh]=new Node(neigh->val);
                    q.push(neigh);
                }
                //if already exists,push to the clone node neighbors
                mp[cur]->neighbors.push_back(mp[neigh]);
            }
        }
        return clone;
    }
};