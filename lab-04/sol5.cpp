#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int data){
        val=data;
        left=right=NULL;
        height=1;
    }
};

class AVL{
    public:
    Node* root;

    int height(Node* node){
        if(node==nullptr){return 0;}
        return node->height;
    }
    int b_f(Node* node){
        if(node==nullptr){return 0;}
        return height(node->left)-height(node->right);
    }
    void update_height(Node* node){
        node->height = max(height(node->left),height(node->right))+1;
    }
    Node* right_rotation(Node* x){
        Node* y = x->left;
        Node* T = y->right;
        y->right = x;
        x->left = T;

        update_height(x);
        update_height(y);
        return y;
    }
    Node* left_rotation(Node* x){
        Node* y = x->right;
        Node* T = y->left;
        y->left = x;
        x->right = T;

        update_height(x);
        update_height(y);
        return y;
    }
    Node* insert_node(Node* node , int k){
        if(node==nullptr){return new Node(k);}
        else{
            if(k<node->val){node->left=insert_node(node->left,k);}
            else if(k>node->val){node->right=insert_node(node->right,k);}
            else{return node;}
        }
        int h=1+max(height(node->left),height(node->right));
        node->height=h;
        int bf=b_f(node);
        if(bf>1 && k<node->left->val){
           return right_rotation(node);
        }
        if(bf<-1 && k>node->right->val){
            return left_rotation(node);
         }

        if(bf>1 && k>node->left->val){
            node->left=left_rotation(node->left);
            return right_rotation(node);
        }
        if(bf<-1 && k<node->right->val){
            node->right=right_rotation(node->right);
            return left_rotation(node);
        }
        return node;

    }

    void inorder(Node* node){
        if(node==nullptr){return;}
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }

    void display(Node* node, int s ,int h=10){
        if(node==nullptr){return;}
        s=s+h;
        display(node->right,s);
        cout << endl;
        for(int i=h;i<s;i++){
            cout<<" ";}
        
        cout<<node->val;
        display(node->left,s);
    }
    public:
    AVL() {
        root = nullptr;}

    void insert(int a){
        root=insert_node(root,a);}
    void inorder(){
        inorder(root);
    }

};
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];      // current element
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;  // Insert the key at correct position
    }
}
int main(){
    AVL tree;
    int n=8;
    //vector<int> arr={10,20,30,40,50,25};
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i + 1; // fill with 1 to n
    }
    // Shuffle using random generator
    random_device rd;
    mt19937 g(rd()); // Mersenne Twister for better randomness
    shuffle(perm.begin(), perm.end(), g);


    for(int i=0;i<n;i++){
        tree.insert(perm[i]);}
    cout<<"INSERTION SORT"<<endl;
    insertionSort(perm);
    for(int i=0;i<perm.size();i++){
        cout<<perm[i]<<" ";}
        cout<<endl;
    cout<<"INORDER TRAVERSAL" <<endl;
    tree.inorder();
    tree.display(tree.root,0);

}