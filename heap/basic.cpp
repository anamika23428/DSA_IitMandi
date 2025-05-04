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

    void heapify(vector<int> arr, int i){
        int l= 2*i;
        int r= 2*i+1;
        int largest=-1;
        if(l<size && arr[l]>arr[i]){
            largest=l;
        }
        else{largest=i;}
        if(r<size && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){swap(arr[largest],arr[i]);heapify(arr, largest);}
    }

    void deleteRoot(vector<int> arr){
        int n=size;
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    n = n - 1;
 
    // heapify the root node
    heapify(arr,  0);
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