#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() { root = nullptr; }

    void insert(int val) {
        Node* node = new Node(val);
        if (root == nullptr) {
            root = node;
            return;
        }
        queue<Node*> qu;
        qu.push(root);
        while (!qu.empty()) {
            Node* curr = qu.front();
            qu.pop();
            if (curr->left == nullptr) {
                curr->left = node;
                return;
            } else
                qu.push(curr->left);
            if (curr->right == nullptr) {
                curr->right = node;
                return;
            } else
                qu.push(curr->right);
        }
    }

    bool search(int val) {
        if (!root) return false;
        queue<Node*> qu;
        qu.push(root);
        while (!qu.empty()) {
            Node* curr = qu.front();
            qu.pop();
            if (curr->data == val) {
                cout << "Found" << endl;
                return true;
            }
            if (curr->left) qu.push(curr->left);
            if (curr->right) qu.push(curr->right);
        }
        cout << "Not found" << endl;
        return false;
    }

    void delete_data(int val) {
        if (!root) return;

        Node* target = nullptr;
        Node* last = nullptr;
        Node* parent = nullptr;

        queue<Node*> qu;
        qu.push(root);

        while (!qu.empty()) {
            last = qu.front();
            qu.pop();

            if (last->data == val) target = last;

            if (last->left) {
                parent = last;
                qu.push(last->left);
            }
            if (last->right) {
                parent = last;
                qu.push(last->right);
            }
        }

        if (target) {
            target->data = last->data; // Replace target node with last node's value

            if (parent->right == last) parent->right = nullptr;
            else parent->left = nullptr;

            delete last;
        }
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    Tree bt;
    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);

    cout << "Inorder before deletion: ";
    bt.displayInorder();

    bt.delete_data(30);
    cout << "Inorder after deleting 30: ";
    bt.displayInorder();
}
