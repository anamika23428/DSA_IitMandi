#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
        height=1;
    }
};

class AVL{
    private:
    Node* root;

    int height(Node* node){
        if(node==nullptr){return 0;}
        return node->height;
    }

    Node* right_rotation(Node* x){
        Node* y=x->left;
        Node* T2=y->right;
        y->right=x;
        x->left=T2;
        x->height=1+max(height(x->left),height(x->right));
        y->height=1+max(height(y->left),height(y->right));
        return y;
    }

    Node* left_rotation(Node* x){
        Node* y=x->right;
        Node* T2=y->left;
        y->left=x;
        x->right=T2;

        x->height=1+max(height(x->left),height(x->right));
        y->height=1+max(height(y->left),height(y->right));
        return y;
    }
    int balance_factor(Node* node){
        if(node==nullptr){return 0;}
        return height(node->left)-height(node->right);
    }

    Node* insert(Node* node,int key){
        if(node==nullptr){return new Node(key);}
        if(key < node->data){node->left=insert(node->left,key);}
        else if(key > node->data){node->right=insert(node->right,key);}
        else{return node;}

        int h=1+max(height(node->left),height(node->right));
        node->height=h;
        int bf=balance_factor(node);
        //left left
        if(bf>1 && key<node->left->data){
            return right_rotation(node);
        }
        //right right
        if(bf<-1 && key>node->right->data){
            return left_rotation(node);
            }
        // 
        if(bf>1 && key>node->left->data){
            node->left=left_rotation(node->left);
            return right_rotation(node);
        }
        if(bf<-1 && key<node->right->data){
            node->right=right_rotation(node->right);
            return left_rotation(node);
        }
        return node;
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void display(Node* root, int space = 0, int height = 10) {
        if (!root) return;
    
        space += height;
        display(root->right, space);
    
        cout << endl;
        for (int i = height; i < space; i++)
            cout << ' ';
        cout << root->data;
    
        display(root->left, space);
    }

    Node* right_max(Node* node){
        Node* current = node;
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    }
    Node* deletion(Node* node,int key){
        if(node==nullptr){return node;}
        if(key < node->data){node->left=deletion(node->left,key);}
        else if(key > node->data){node->right=deletion(node->right,key);}
        else{ 
              if(node->left==nullptr || node->right==nullptr){
                Node* temp=node;
                if(temp->left==nullptr){node=temp->right;}
                else{node=temp->right;}
                delete temp;
                return node;
              }
              //2 children -- 
              else{
                Node* temp= right_max(node->right);
                node->data= temp->data;
                node->right=deletion(node->right,temp->data);
                int h=1+max(height(node->left),height(node->right));
        node->height=h;
        int bf=balance_factor(node);
        //left left
        if(bf>1 && key<node->left->data){
            return right_rotation(node);
        }
        //right right
        if(bf<-1 && key>node->right->data){
            return left_rotation(node);
            }
        // 
        if(bf>1 && key>node->left->data){
            node->left=left_rotation(node->left);
            return right_rotation(node);
        }
        if(bf<-1 && key<node->right->data){
            node->right=right_rotation(node->right);
            return left_rotation(node);
        }

    }
        return node;}
    }
    public:
    AVL(){
        root=NULL;
    }
    void insert(int a){
        root=insert(root,a);
    }
    void inorder(){
        inorder(root);
    }
    void display(){
        display(root);
    }
    void delete_node(int k){
        root=deletion(root,k);
    }

};

int main(){
    AVL tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(5);
    tree.insert(8);
    
    tree.inorder();
    tree.display();
    tree.delete_node(40);
    tree.display();
    return 0;

}