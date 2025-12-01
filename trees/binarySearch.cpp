#include <iostream>
using namespace std;

// Node for BST
struct Node
 {
    int data;
    Node *left, *right;
};

// Create a new node
Node* newNode(int value)
 {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert node into BST
Node* insert(Node* root, int value)
 {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// ------------------ TRAVERSALS ------------------

void inOrder(Node* root)
 {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root)
 {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
 {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// ---------------- MIN & MAX ----------------

int min_value(Node* root)
 {
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp->data;
}

int max_value(Node* root) 
{
    Node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp->data;
}

// -------------- COUNT NODES ----------------

int NumberOfNodes(Node* root) 
{
    if (root == NULL) return 0;
    return 1 + NumberOfNodes(root->left) + NumberOfNodes(root->right);
}

// -------------- LEAF NODES ----------------

void LeafNodes(Node* root) 
{
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    LeafNodes(root->left);
    LeafNodes(root->right);
}

// -------------- INTERNAL NODES ----------------

void InternalNodes(Node* root)
 {
    if (root == NULL) return;

    if (root->left != NULL || root->right != NULL)
        cout << root->data << " ";

    InternalNodes(root->left);
    InternalNodes(root->right);
}



int main()
 {

    // Building BST with same values as the binary tree example

    /*
            10
          /    \
        5        20
       / \      /
      2   7    15
    */

    int values[] = {10, 5, 20, 2, 7, 15};
    Node* root = NULL;

    for (int v : values)
        root = insert(root, v);

    cout << "Inorder Traversal (sorted): ";
    inOrder(root);

    cout << "\nPreorder Traversal: ";
    preOrder(root);

    cout << "\nPostorder Traversal: ";
    postOrder(root);

    cout << "\n\nMin Value: " << min_value(root);
    cout << "\nMax Value: " << max_value(root);
    cout << "\nTotal Nodes: " << NumberOfNodes(root);

    cout << "\nLeaf Nodes: ";
    LeafNodes(root);

    cout << "\nInternal Nodes: ";
    InternalNodes(root);

    return 0;
}
