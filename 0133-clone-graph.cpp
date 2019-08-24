/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<int, Node*> newNodes;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        unordered_map<int, Node*>::iterator it = newNodes.find(node->val);
        if (it != newNodes.end()) {
            return it->second;
        }
        
        vector<Node*> neighbors;
        Node* newNode = newNodes[node->val] = new Node(node->val, neighbors);

        for (int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        return newNode;
    }
};
