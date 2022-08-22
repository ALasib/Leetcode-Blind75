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
        if(node==NULL){
            return NULL;
        }
        
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        
        Node* copy = new Node(node->val);
        m[node]=copy;
        q.push(node);
        
        while(!q.empty()){
            Node* source = q.front();
            q.pop();
            
            int sz = source->neighbors.size();
            for(int i=0;i<sz;i++){
                Node* adj = source->neighbors[i];
                if(m.find(adj)==m.end()){
                    m[adj]=new Node(adj->val);
                    q.push(adj);
                }
                m[source]->neighbors.push_back(m[adj]);
            }
        }
        return copy;
    }
};
