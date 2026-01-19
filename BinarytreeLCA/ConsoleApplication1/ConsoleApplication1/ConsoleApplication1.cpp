#include <iostream>
using namespace std;

// Node Structure
class Node {
public:
    Node* left, * right;
    int data;
    Node(int k) {
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

Node* lca(Node* root, int n1, int n2) {

    if (!root)
        return nullptr;


    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLca = lca(root->left, n1, n2);
    Node* rightLca = lca(root->right, n1, n2);


    if (leftLca && rightLca)
        return root;


    return leftLca ? leftLca : rightLca;
}

int main() {

    // construct the binary tree
    //			   1
    //           /   \
    //          2     3
    //         / \   / \
    //        4  5  6   7 
    //             /
    //            8

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    Node* ans = lca(root, 7, 8);

    cout << ans->data;

    return 0;
}