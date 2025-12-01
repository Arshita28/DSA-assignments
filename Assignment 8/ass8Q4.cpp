#include <iostream>
#include <limits.h>
using namespace std;

// Structure for each node of the tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

bool checkBST(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    // Example Tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (checkBST(root))
        cout << "This tree is a BST\n";
    else
        cout << "This tree is NOT a BST\n";

    return 0;
}
