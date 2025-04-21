#include<bits/stdc++.h>
using namespace std;

struct Node{
    int prio;
    string value;
    Node* left;
    Node* right;

    Node(int p,string s){
        prio=p;
         value=s;
        left=right=nullptr;
    }
};

class Priorityqueue{
    private:
    Node* root;

    Node* insert(Node* node,int p,string s){
        if(node==nullptr){return new Node(p,s);}
        if(p>node->prio){node->right= insert(node->right,p,s);}
        else{node->left= insert(node->left,p,s);}
        return node;
    }

    Node* delete_min(Node* node){
        Node* temp=node;
        if(node==nullptr){return node;}
        if(node->left==nullptr){return node->right;}

        while(temp->left->left){
            temp=temp->left;
        }
        temp->left=nullptr;
        return node;
    }

    void search(Node* node,string k,int &comp){
        comp++;
        if(node==nullptr){return;}
        if(k==node->value){cout<<"found"<<endl;return;}
            search(node->left,k,comp);
            search(node->right,k,comp);    
    }

    void inorder(Node* node){
        if(node==nullptr){return;}
        inorder(node->left);
        cout<<node->value<<"-"<<node->prio<<" ";
        inorder(node->right);
    }
    public:
    Priorityqueue(){
    root= nullptr;}

    void insert(int p,string s){
        root=insert(root,p,s);
    }
    void delete_min(){
        root=delete_min(root);
    }
    void inorder(){
        inorder(root);
    }
    void search(string s){
        int comp=0;
        search(root,s,comp);
        cout<<"comparisons: "<<comp<<endl;
    }

};

int main(){
    Priorityqueue pq;
    pq.insert(5,"A");
    pq.insert(3,"B");
    pq.insert(7,"C");
    pq.inorder();
    pq.delete_min();
    pq.inorder();
    pq.search("A");
    return 0;
}