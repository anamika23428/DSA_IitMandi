#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) {
        data=value;
        next=NULL;}
};

struct Stack{
    Node* top;

    Stack(){ top = nullptr;}


    bool isempty(){
        if (top== nullptr){
            return true;
        }
        return false;
    }


    void push(int data){

        Node* temp = new Node(data);
        temp->next=top;
        top=temp;

    }

    int pop(){
        if(isempty()){cout<<"stack is empty"; return -1;}
        Node* temp=top;
        int value  = temp->data;
        top=top->next;
        delete temp;
        return value;

    }

    int peek(){
        if(isempty()){cout<<"stack is empty"; return -1;}

        return top->data;

    }
    void display (){

        Node* temp=top;
        while(temp!=nullptr){
            cout<<temp->data<<"<--";
            temp=temp->next;
        }
        cout<<endl;
    }

};

void movedisk(int n, Stack& source, Stack& tar ,Stack& via ,char A ,char C, char B){
    if(n<=0){return;}

    movedisk(n-1 , source, via, tar ,A ,B, C);
    int disk = source.pop();
    if(disk !=-1){
        tar.push(disk);
        cout<<"moved disk "<< disk<<" from "<<A <<" to "<<C<<endl;
    }
    movedisk(n-1, via, tar, source ,B,C,A);
}
int main(){
    int n ;
    cin>>n;
    Stack source, via, target;

    for (int i = n; i >= 1; i--)
        source.push(i);

    movedisk(n, source, target, via, 'A', 'C', 'B');

    return 0;

}
