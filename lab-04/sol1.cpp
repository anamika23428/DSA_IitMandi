#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
   // Node* parent;

    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }
    //insert
    Node* insert(Node* node, int data) {
        if (node == nullptr) return new Node(data);
        if (data < node->val)
            node->left = insert(node->left, data);
        else if (data > node->val)
            node->right = insert(node->right, data);
        return node;
    }

    void insert(int data) {
        root = insert(root, data); 
    }


    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    // search 
    Node* search(Node* node,int k){
        if(node==nullptr || node->val== k ){
            return node;
        }
        if(node->val<k){
            return search(node->right,k);}
        else{
            return search(node->left,k);
        }
    }

    void search(int k){
        cout<<endl;
        Node* node = search(root,k);
        if(node==nullptr){cout<<k<<" is not found";}
        else{cout<<"Not found";}
    }
    // delete

//     Node* fun(Node* node){
//         while(node->right){
//             node=node->right;
//         }
//         return node;
//     }
//     Node* helper(Node* node){
//         if(node->left==nullptr){
//             return node->right;
//         }
//         else if(node->right==nullptr){
//             return node->left;
//         }
//         else{
//             Node* rightchild= node->right;
//             Node* leftmax= fun(node->left);
//             leftmax->right= rightchild;
//             return node->left;
//         }
//     }

//     Node* delete_(Node* node,int tod){
//         if(node==nullptr){return nullptr;}
//         if(node->val==tod){return helper(node);}

//         Node* temp= node;
//         while(temp){
//             if(temp->val>tod){
//                 if(temp->left!=nullptr && temp->left->val== tod){
//                     temp->left= helper(temp->left);
//                     break;
//                 }
//                 else{
//                     temp=temp->left;
//                 }
//             }
//             else{
//                 if(temp->right!=nullptr && temp->right->val== tod){
//                     temp->right= helper(temp->right);
//                     break;
//                 }
//                 else{
//                     temp=temp->right;
//                 }
//         }
//     }
//     return node;
// }
        Node* fun(Node* node){
            while(node->left){
                node=node->left;
            }
            return node;
        }
        Node* delete_(Node* node ,int k){
            if(node==nullptr){return nullptr;}
            if(node->val>k){node->left=delete_(node->left,k);}
            else if(node->val<k){node->right=delete_(node->right,k);}
            else{
                if(node->left==nullptr ||node->right==nullptr){
                    return node->left!=nullptr?node->left:node->right;
                }
                else{
                    Node* temp=fun(node->right);
                    node->val=temp->val;
                    node->right=delete_(node->right,temp->val);
            }
            return node;
        }
    }
        void delete_node(int k){
            root= delete_(root, k);
        }

};

int main() {
    BST bst;
    bst.insert(3);
    bst.insert(5);
    bst.insert(8);
    bst.insert(1);
    bst.inorder(bst.root);  
    bst.search(4);
    bst.delete_node(5);
    bst.inorder(bst.root);
    

}