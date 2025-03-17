#include<bits/stdc++.h>
using namespace std;

class tickbook{
    private:
    vector<int> qu;
    int front,rear,size,cap;
    public:
    tickbook(int c){
        cap=c;
        qu.resize(cap);
        front=-1; rear=-1;size=0;}

    bool isfull(){return size==cap;}
    bool isempty(){return size==0;}
    void booktic(int id){
        if(isfull()){
            cout<<"NO availabe space"<<endl;
            return ;
        }
        else if(isempty()){front=0;}
        rear=(rear+1)%cap;
        qu[rear]= id;
        size++;
    }
    void alloc(){
        if(isempty()){
            cout<<"No ticket booked"<<endl; return;}
        else{
            cout<<"Ticket allocated to "<<qu[front]<<endl;
            front=(front+1)%cap;
            size--;
            if(isempty()){front=rear=-1;}
    }
    }

    void display(){
        int cnt=0;
        int i=front;
        while(cnt<cap){
            cout<<qu[i]<<" ";
            i=(i+1)%cap;
            cnt++;
            }
        }
    
};

int main(){
    int n;
    cout<<"capacity of qu";
    cin>>n;
    tickbook t(n);
    int choice;
    int id;
    while(true){
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter id";
            cin>>id;
            t.booktic(id);
            break;
            case 2: t.alloc();
            break;
            case 3: t.display();
            break;
            case 4: exit(0); return 0;
            default: cout<<"Invalid choice"<<endl;
            }


    }}