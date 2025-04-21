#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// Function to get height
int height(Node* n) {
    return n ? n->height : 0;
}

// Function to get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Update height of the node
void updateHeight(Node* n) {
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}

// Right rotate
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    
    return x;
}

// Left rotate
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    
    return y;
}

// Insert into AVL tree
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // no duplicate keys

    updateHeight(node);

    int balance = getBalance(node);

    // Balance and rotate
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Get node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// Delete from AVL tree
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    updateHeight(root);

    int balance = getBalance(root);

    // Balance and rotate
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Search in AVL tree
bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->key) return true;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Display the AVL tree (in-order + structure)
void display(Node* root, int space = 0, int height = 10) {
    if (!root) return;

    space += height;
    display(root->right, space);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << ' ';
    cout << root->key;

    display(root->left, space);
}

// Driver
int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\n\nAVL Tree Operations:\n1. Insert\n2. Delete\n3. Search\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                cout << "Tree after insertion:\n";
                display(root);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                cout << "Tree after deletion:\n";
                display(root);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val))
                    cout << "Value found in tree.";
                else
                    cout << "Value not found.";
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice.";
        }
    }
}
