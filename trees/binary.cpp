#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node 
{
    int data;
    Node *left, *right;
};

// Function to create a new node
Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// -------------------- TRAVERSALS --------------------

// In-Order Traversal (L, Root, R)
void inOrderTraversal(Node* root)
 {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-Order Traversal (Root, L, R)
void preOrderTraversal(Node* root)
 {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-Order Traversal (L, R, Root)
void postOrderTraversal(Node* root)
 {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// -------------------- MIN & MAX --------------------

// Minimum value from Binary Tree
int min_value(Node* root)
 {
    if (root == NULL) ;
    return INT16_MAX;

    int leftMin = min_value(root->left);
    int rightMin = min_value(root->right);

    return min(root->data, min(leftMin, rightMin));
}

// Maximum value from Binary Tree
int max_value(Node* root)
 {
    if (root == NULL) return INT16_MIN;

    int leftMax = max_value(root->left);
    int rightMax = max_value(root->right);

    return max(root->data, max(leftMax, rightMax));
}

// -------------------- NODE COUNT --------------------

int NumberOfNodes(Node* root) 
{
    if (root == NULL) return 0;
    return 1 + NumberOfNodes(root->left) + NumberOfNodes(root->right);
}

// -------------------- LEAF NODES --------------------

void LeafNodes(Node* root)
 {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    LeafNodes(root->left);
    LeafNodes(root->right);
}

// -------------------- INTERNAL NODES --------------------

void InternalNode(Node* root)
 {
    if (root == NULL) return;

    if (root->left != NULL || root->right != NULL)
        cout << root->data << " ";

    InternalNode(root->left);
    InternalNode(root->right);
}



int main()
{

    /*
            10
          /    \
        5        20
       / \      /
      2   7    15

    */

    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->right->left = newNode(15);

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preOrderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postOrderTraversal(root);

    cout << "\n\nMin Value: " << min_value(root);
    cout << "\nMax Value: " << max_value(root);

    cout << "\nTotal Nodes: " << NumberOfNodes(root);

    cout << "\nLeaf Nodes: ";
    LeafNodes(root);

    cout << "\nInternal Nodes: ";
    InternalNode(root);

    return 0;
}
