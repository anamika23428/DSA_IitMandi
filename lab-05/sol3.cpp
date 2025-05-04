#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void heapify(vector<int>& arr, int size, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest=-1;
    if(l<size && arr[l]>arr[i]){
        largest=l;
    }
    else{largest=i;}
    if(r<size && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){swap(arr[largest],arr[i]);heapify(arr,size, largest);}
}

void heapSort(vector<int>& arr) {
    int n = arr.size();


    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);    // Heapify reduced heap
    }
}


int main() {
    vector<int> arr = {3, 4, 5, 7};
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr,n, i);
    }

    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    heapSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    
}


