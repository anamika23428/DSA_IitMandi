#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void heapify(vector<int>& arr, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest=-1;
    int size=arr.size();
    if(l<size && arr[l]>arr[i]){
        largest=l;
    }
    else{largest=i;}
    if(r<size && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){swap(arr[largest],arr[i]);heapify(arr, largest);}
}

int main(){
    vector<int> arr={3,4,5,7};

    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i);
    }
    for(int i:arr){cout<<i<<endl;}
    cout<<"MAX:"<<arr[0];
    cout<<"Extarct max";
    arr[0]=arr.back();
    arr.pop_back();
    heapify(arr,0);
    for(int i:arr){cout<<i<<endl;}
}