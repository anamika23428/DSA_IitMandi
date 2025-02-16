#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
class doublell{
    public:
    Node* head;
    doublell(){
        head=nullptr;
    }

    void insert_at_tail(int data){
        Node* node=new Node(data);
        if(head == nullptr){
            head=node;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=node;
        node->prev=temp;

    }
    void print(){
        if(head== nullptr){return;}
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"  ";
            
            temp=temp->next;
        }
    }

    void sorting(){
        if(head==nullptr){return;}
        
        Node* tempi=head;
        while(tempi!=nullptr){
            Node* tempj = tempi;
            while(tempj->prev!=nullptr && tempj->prev->data>tempj->data){
                int extra= tempj->data;
                tempj->data=tempj->prev->data;
                tempj->prev->data=extra;
                tempj=tempj->prev;
            }
            tempi=tempi->next;
        }
    }

};
int main(){
    doublell dll;
    dll.insert_at_tail(3);
    dll.insert_at_tail(6);
    dll.insert_at_tail(2);
    dll.insert_at_tail(1);
    dll.insert_at_tail(19);
    dll.insert_at_tail(2);
    dll.sorting();
    dll.print();
}