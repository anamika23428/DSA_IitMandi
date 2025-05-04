#include<bits/stdc++.h>
using namespace std;
#include<iostream>

struct Node{
    int val;
    Node* next;
    Node(int k){val=k;next=nullptr;}
};

Node* merge(vector<Node*> lists){
    auto cmp = [](Node* a, Node* b) {
        return a->val > b->val;
    };
    priority_queue< Node*, vector<Node*>, decltype(cmp)> minHeap(cmp);

    for(auto & node:lists){
        minHeap.push(node);
    }
    Node* res=new Node(0);
    Node* temp=res;
    while(!minHeap.empty()){
        Node* minele=minHeap.top();
        minHeap.pop();
        temp->next=minele;
        temp=temp->next;
        if(minele->next){
        minHeap.push(minele->next);}
    }
    return res->next;
}

Node* create(vector<int>arr){
    Node* a=new Node(arr[0]);
    Node* temp=a;
    for(int i=1;i<arr.size();i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return a;
}
int main(){
    vector<int> k1={3,5,6};
    vector<int> k2={4,9,11};
    vector<Node*> lists;

    

    lists.push_back(create(k1));
    lists.push_back(create(k2));

    Node* res=merge(lists);
    Node* head=res;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}