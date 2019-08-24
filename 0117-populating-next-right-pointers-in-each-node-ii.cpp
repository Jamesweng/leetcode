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
        
        if (root->left && root->right) {
            Node* p1 = root->left;
            Node* p2 = root->right;
            
            while (p1 && p2) {
                Node* x = p1;
                
                while (p1 && !p1->left && !p1->right) p1 = p1->next;
                if (p1) {
                    if (p1->left) p1 = p1->left;
                    else p1 = p1->right;
                }
                
                while (x->next) x = x->next;
                x->next = p2;
                
                while (p2 && !p2->left && !p2->right) p2 = p2->next;
                if (p2) {
                    if (p2->left) p2 = p2->left;
                    else p2 = p2->right;
                }
                
            }
        }
        
        return root;
    }
};
