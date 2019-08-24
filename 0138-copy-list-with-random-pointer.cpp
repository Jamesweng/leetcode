/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        unordered_map<int, Node*> nodeMap;
        
        Node *new_head = new Node(head->val, NULL, NULL);
        Node * p = new_head;
        nodeMap[p->val] = p;
        
        
        for (Node *q = head; q->next != NULL;) {
            q = q->next;
            p->next = new Node(q->val, NULL, NULL);
            p = p->next;
            nodeMap[p->val] = p;
        }
        
        for (Node *q = head, *p = new_head; q != NULL; ) {
            if (q->random) {
                p->random = nodeMap[q->random->val];
            }
            p = p->next;
            q = q->next;
        }
        
        return new_head;
    }
};
