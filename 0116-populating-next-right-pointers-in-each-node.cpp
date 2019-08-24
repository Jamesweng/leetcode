/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        root->next = NULL;
        connect(root->left);
        connect(root->right);
        
        Node* p1 = root->left;
        Node* p2 = root->right;
        while (p1 != NULL && p2 != NULL) {
            p1->next = p2;
            p1 = p1->right;
            p2 = p2->left;
        }
        
        return root;
    }
};
