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


void increase_key(vector<int>& arr,int i,int key){
    arr[i]=key;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(vector<int>& arr,int key){
   int n=arr.size();
   arr.push_back(INT_MIN);
   increase_key(arr,n,key);
}
int main() {
    vector<int> arr = {3, 4, 5, 7};
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, i);
    }

    cout << "Heap after build:\n";
    for (int i : arr) cout << i << " ";
    cout << "\n";

    cout << "MAX: " << arr[0] << "\n";
    cout << "Extract max\n";
    arr[0] = arr.back();
    arr.pop_back();
    heapify(arr, 0);

    cout << "Heap after extract max:\n";
    for (int i : arr) cout << i << " ";
    cout << "\n";

    insert(arr, 9);
    cout << "Heap after inserting 9:\n";
    for (int i : arr) cout << i << " ";
    cout << "\n";
}
