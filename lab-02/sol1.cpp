#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){val=data; next=nullptr;}
    Node(int data ,Node* ptr){val=data; next=ptr;}

    Node* insert_at_head(int data,Node* head){
        if(head==nullptr){return head;}
        Node* node = new Node(data,head);
    return node;
    }
    Node* delete_at_head(Node* head){
        return head->next;
    }
    Node* insert_at_tail(int data,Node* head){
        Node* node = new Node(data);
        Node* temp = head;
        if(head==nullptr){return node;}
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=node;
        return head;
    }
    Node* delete_at_tail(Node* head){
        Node* temp = head;
        if(head==nullptr){return nullptr;}
        if(head->next==nullptr){return nullptr;}
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nullptr;
        return head;
    }
    Node* insert_at_kth(int data,Node* head ,int k){
        Node* node = new Node(data);
        Node* temp = head;
        if(head==nullptr){return node;}
        int i=1;
        if(k==1){return insert_at_head(data,head);}
        while(temp->next!=nullptr && i<k-1 ){
            temp=temp->next;
            i++;
        }
        Node* npp=temp->next;
        temp->next=node;
        node->next=npp;
        return head;
    }
    Node* delete_at_kth(Node* head ,int k){
        Node* temp = head;
        if(head==nullptr){return nullptr;}
        int i=1;
        if(k==1){return delete_at_head(head);}
        while(temp->next!=nullptr && i<k-1 ){
            temp=temp->next;
            i++;
        }
        Node* npv=temp->next->next;
        temp->next->next=nullptr;
        temp->next=npv;
        return head;
    }


    void print(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<"-->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    Node* head = new Node(1);
    head = head->insert_at_tail(2 , head);
    head = head->insert_at_tail(3 , head);
    // head = head->insert_at_tail(4 , head);
    head = head->insert_at_tail(5 , head);
    head->print(head);
    cout<<endl;
    head=head->insert_at_kth(4,head,4);
    head->print(head);
    cout<<endl;
    head=head->delete_at_tail(head);
    head->print(head);
    head=head->delete_at_kth(head,3);
    head->print(head);
}
