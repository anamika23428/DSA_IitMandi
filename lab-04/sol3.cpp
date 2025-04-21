#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

class BinaryTree{
    public:
    Node* root;
    BinaryTree(){
        root = nullptr;
    }

    // Traversals
    void preorder(Node* node) {
        if (!node) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }
    
};


class BST {
    public:
        Node* root;
    
        BST() {
            root = nullptr;
        }
    
        Node* insert(Node* node, int val) {
            if (!node) return new Node(val);
            if (val < node->val)
                node->left = insert(node->left, val);
            else
                node->right = insert(node->right, val);
            return node;
        }
    
        void insert(int val) {
            root = insert(root, val);
        }
    
        // Traversals
        void preorder(Node* node) {
            if (!node) return;
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    
        void inorder(Node* node) {
            if (!node) return;
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    
        void postorder(Node* node) {
            if (!node) return;
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
    };


int main(){

    BinaryTree bt;
    bt.root = new Node(1);
    bt.root->left = new Node(2);
    bt.root->right = new Node(3);
    bt.root->left->left = new Node(4);
    bt.root->left->right = new Node(5);

    cout << "Binary Tree Traversals:\n";
    cout << "Pre-order: "; bt.preorder(bt.root); cout << endl;
    cout << "In-order: "; bt.inorder(bt.root); cout << endl;
    cout << "Post-order: "; bt.postorder(bt.root); cout << endl;

    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << "\nBinary Search Tree Traversals:\n";
    cout << "Pre-order: "; bst.preorder(bst.root); cout << endl;
    cout << "In-order: "; bst.inorder(bst.root); cout << endl;
    cout << "Post-order: "; bst.postorder(bst.root); cout << endl;
}
    