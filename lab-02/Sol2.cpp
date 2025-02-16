#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){val=data; next=nullptr; prev=nullptr;}
    Node(int data ,Node* nextptr ,Node* prevptr ){val=data; next=nextptr; prev=prevptr;}

    Node* insert_at_head(int data,Node* head){
        if(head==nullptr){return head;}
        Node* node = new Node(data,head ,nullptr);
    return node;
    }
    Node* delete_at_head(Node* head){
        if(head==nullptr){return head;}
        head->next->prev=nullptr;

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
        node->prev= temp;
        return head;
    }


    Node* delete_at_tail(Node* head){
        Node* temp = head;
        if(head==nullptr){return nullptr;}
        if(head->next==nullptr){return nullptr;}
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
Node* node=temp->next;
node->prev=nullptr;
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
        node->prev=temp;
        node->next=npp;
        npp->prev=node;
        return head;
    }

    Node* delete_at_kth(Node* head ,int k){
        Node* temp = head;
        if(head==nullptr){return nullptr;}
        int i=1;
        if(k==1){return delete_at_head(head);}
        while(temp!=nullptr && i<k ){
            temp=temp->next;
            i++;
        }
        if(temp==nullptr){return head;}
        Node* npp=temp->prev;
        Node* npn=temp->next;
       
       if(npn==nullptr){return delete_at_tail(head);} 
       delete(temp);
       npp->next=npn;
        npn->prev=npp;
        return head;
    }
    void print(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<"<->";
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
    head=head->delete_at_head(head);
    head->print(head);
    cout<<endl;
    head=head->delete_at_tail(head);
    head->print(head);
  cout<<endl;
  head=head->delete_at_kth(head,3);
  cout<<"delete at kth"<<endl;
    head->print(head);
  cout<<endl;
  head = head->insert_at_tail(4 , head);
  head->print(head);
  cout<<endl;
}
