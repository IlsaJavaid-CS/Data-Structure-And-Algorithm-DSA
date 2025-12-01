#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int v) {
    Node* n = new Node;
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

Node* createTree() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    return root;
}

void LeafNodes(Node* root) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }

    LeafNodes(root->left);
    LeafNodes(root->right);
}

int main() {
    Node* root = createTree();
    LeafNodes(root);
}
