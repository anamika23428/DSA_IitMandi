#include<bits/stdc++.h>
using namespace std;

class max_heap{
    public:
    int arr[100];
    int size;
    max_heap(){
        size = 0;
        arr[0]=-1;
    }

    void insert(int val){
        if(size==100){cout<<"heap is full"<<endl;return ;}
        size++;
        arr[size]=val;
        int idx=size;
        while(idx>1){
            int parent=idx/2;
            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{return;}
        }
    }


    void delete_root(){
        if(size==0){cout<<"heap is empty"<<endl;return ;}
        arr[1]=arr[size];
        size--;
        int idx=1;
        while(idx<size){
            int left=2*idx;
            int right=2*idx+1;
            if(left<size && arr[left]>arr[idx]){
                swap(arr[left],arr[idx]);
                idx=left;
            }
            else if(right<size && arr[right]>arr[idx]){
                swap(arr[right],arr[idx]);
                idx=right;
                }
            else{return ;}
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";}
            cout<<endl;
    }
};

int main(){
    max_heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(15);
    h1.insert(5);
    h1.print();
    h1.insert(30);
    h1.print();
}